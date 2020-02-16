echo *.cpp *.sh *.py > filenames.txt
cat README.template > README.md
echo "| Problem | Language | " >> README.md
echo "|:-------:|:--------:| " >> README.md
python3 createReadme.ignore.py filenames.txt >> README.md
rm filenames.txt