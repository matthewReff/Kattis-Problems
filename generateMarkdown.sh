echo *.cpp *.py *.c *.c# *.cc *.cs *.cxx *.go *.hs *.java *.js *.m *.pas *.php *.pl *.rb > temp.txt
python3 seperateNames.ignore.py temp.txt > filenames.txt
cat README.template > README.md
echo "| Problem | Language | " >> README.md
echo "|:-------:|:--------:| " >> README.md
python3 createReadme.ignore.py filenames.txt >> README.md
rm filenames.txt
rm temp.txt