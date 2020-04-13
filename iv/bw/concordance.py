# TESTED:
# python3.5 concordance.py < concordance-sample.in > concordance-sample.given
# vimdiff concordance-sample.expected concordance-sample.given
# => Looks good to me.
#
# time python3.5 concordance.py < concordance-economic-principles.in \
#  > concordance-economic-principles.given 
# real    0m1.355s
# user    0m1.352s
# sys 0m0.000s
# => Manually checked. Looks good.
# 
# == Problem statement
# Given an arbitrary text document written in English,
# write a program that will generate a concordance,
# i.e. an alphabetical list of all word occurrences,
# labeled with word frequencies.
# Bonus: label each word with the sentence numbers in which each occurrence appeared.
# Clarification: Lets print x,y,z,aa,ab,ac "Excel column like", instead of
#                x, y, z, aa, bb, cc as in the example. This is essentially
#                base 26, with 0->a, 1->b, ... .
#
# First thoughts:
# [0] This almost exactly same as the inverted document index used at Google.
#     We call it "Posting list", and it's Webs concordance where instead of
#     sentence numbers we use document numbers (We have lot of algos to 
#     reduce the storage and decoding resource cost).
# [1] Maximum document size? If we disregard arbitrary long generated web pages,
#     then O(1M) words.
#     => Python wil be fast enough, good for text manipulation.
# [2] How are sentences separated?
#     For simplicity, lets assume by ['.', '?', '!'],
#     TODO cases like "???", or "Peter said: 'What is a word?'."
# [3] What's a word? Lets assume sequence of [a-zA-Z]+, or in Python \W+.
#     And the lowercase everything.
# [4] What's the simplest approach? Lets split first to sentences, then
#     traverse all sentences and build a dictionary of word -> list[sentence_id]
#     Finally, print out the concordance.

import re
import sys
import collections

LOG_VERBOSE = False

# Maps word -> [sentence ids]
concordance = {}
SENTENCE_SPLITTERS = ['.', '!', '?']

def ProcessSentence(sentence, sentence_id, concordance):
  if LOG_VERBOSE: print("sentence: ", sentence)

  # TODO what about "nitty-gritty"? Lets split it for now, as 10-4=6
  sentence = re.sub('[/*-+=]', ' ', sentence)
  # TODO what about 10th? and how we got "apr34"?

  # words = re.split('\W+', sentence)
  # Split by whitespaces to support abbreviations, that needs to filter.
  # TODO Expect known abbreviations.
  words = sentence.split()  # More readable then moving into comprehension.
  words = [re.sub('[^\w%.’©]+', '', word) for word in words]
  # The previous keeps "." in all places, for "e.g." or "3.14", or "-10.0%"
  # but also "appeared.", so lets just strip the last occurence.
  words = [re.sub('[.`]$', '', word) for word in words]

  for word in words:
    if LOG_VERBOSE: print("  word: ", word)
    if len(word) == 0: continue
    if len(word) == 1 and word in SENTENCE_SPLITTERS: continue
    key = word.lower()
    if key not in concordance:
      concordance[key] = [sentence_id]
    else:
      concordance[key].append(sentence_id)

# Disclaimer: we cannot decide if the last output item is a sentence or not,
# as we need to verify the next sentence starts with [A-Z]
# Note: It is considered untidy to start sentences with figures (The Internet).
def SplitStringToSentences(s):
  sentences = []
  start = 0
  end = 0
  while end < len(s):
    while end < len(s) and s[end] not in SENTENCE_SPLITTERS:
      end += 1
    if LOG_VERBOSE: print(start, end)
    # End of string, or unable to verify start of next, push what we have.
    # Note we compare to " - 3" so we can access the next two indeces.
    if end > len(s) - 3:
      sentences.append(s[start:])
      return sentences
    # Verify that next is a capital letter and previous it's a long enough word.
    if (re.match('[A-Z]', s[end + 2]) and
        end > 1 and  # One character sentences upon discussion.
        re.match('[A-Za-z0-9][A-Za-z0-9]', s[end - 2 : end])):
      sentences.append(s[start:end])
      start = end
    end += 1  # Infinity loop.
  return sentences
    

document_buffer = ""
sentence_id = 1  # Arguably this should be owned by ProcessSentence.
# Reading the document line-by-line prevents storing the whole thing in memory.
for line in sys.stdin:
  if LOG_VERBOSE: print("Line: ", line)
  # TODO: Fix the O(line^2) problem when whole document is one sentence,
  # and everytime we grow the buffer and try to match it.
  document_buffer += line
  # TODO: Fix "abbrv. Capital"
  sentences = SplitStringToSentences(document_buffer)
  # Simpler way for the record (which doesn't support abbrv)
  # sentences = re.split('[.!?]', document_buffer)

  if LOG_VERBOSE: print(sentences)

  # Last sentence might be incomplete. Therefore we keep it in the
  # document buffer to resolve it.
  for i in range(len(sentences) - 1):
    ProcessSentence(sentences[i], sentence_id, concordance)
    sentence_id += 1
  document_buffer = sentences[len(sentences) - 1]
  if LOG_VERBOSE: print("Document buffer: ", document_buffer)
ProcessSentence(document_buffer, sentence_id, concordance)
sentence_id += 1

# Precondition number > 0
def IntToExcelColumn(number):
  result = []  # String are immutable
  while True:  # Emulate do-while
    number -= 1
    # This produces big endian.
    result.append(chr(ord('a') + (number % 26)))
    number //= 26
    if number <= 0: break
  # TODO: Argue if "z" should be followed by "aa, ab, ac, .." or "ba, bb, bc"
  # is good enough. 
  return "".join(result[::-1])

word_id = int(1)
for word, occurences in sorted(concordance.items()):
  print(IntToExcelColumn(word_id) + ". " + word + " {" + str(len(occurences)) +
        ":" + ','.join([str(sent_id) for sent_id in occurences]) + "}")
  word_id += 1
 
