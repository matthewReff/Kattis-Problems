import sys
import re

if len(sys.argv) == 1:
    print("Give a filename as an argument")
    exit(1)
elif len(sys.argv) > 2:
    print("Only 1 filename is needed")
    exit(1)
    
KATTIS_PROBLEM_PREFIX = "https://open.kattis.com/problems/"
GITHUB_LINK_PREFIX = "https://github.com/matthewReff/Kattis-Problems/code/blob/master/"

#shamelessly taken from kattis's official submission script
_LANGUAGE_GUESS = {
    'c': 'C',
    'c#': 'C#',
    'c++': 'C++',
    'cc': 'C++',
    'cpp': 'C++',
    'cs': 'C#',
    'cxx': 'C++',
    'go': 'Go',
    'h': 'C++',
    'hs': 'Haskell',
    'java': 'Java',
    'js': 'JavaScript',
    'm': 'Objective-C',
    'pas': 'Pascal',
    'php': 'PHP',
    'pl': 'Prolog',
    'py': 'Python',
    'rb': 'Ruby'
}

filename = sys.argv[1]    
with open(filename) as fileObj:
    for line in fileObj:
        reg = re.search(r"(.*\/|)(.+)", line)
        problemFileName = reg.group(2)
        splitFile = problemFileName.split(".")
        if len(splitFile) == 2:
            markdownRow = "|"
            markdownRow += "[" + splitFile[0] + "]"
            markdownRow += "(" + KATTIS_PROBLEM_PREFIX + splitFile[0] + ")"
            markdownRow += "|"
            markdownRow += "[" + _LANGUAGE_GUESS[splitFile[1].rstrip()] + "]"
            markdownRow += "(" + GITHUB_LINK_PREFIX + line.rstrip() + ")"
            markdownRow += "|"
            print(markdownRow)
