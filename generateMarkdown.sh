# add entensions as needed for the languages you use
# *.cpp *.py *.c *.c# *.cc *.cs *.cxx *.go *.hs *.java *.js *.m *.pas *.php *.pl *.rb
echo *.cpp *.py > temp.txt
python3 seperateNames.ignore.py temp.txt > filenames.txt
cat README.template > README.md
echo "| Problem | Language | " >> README.md
echo "|:-------:|:--------:| " >> README.md
python3 createReadme.ignore.py filenames.txt >> README.md
rm filenames.txt
rm temp.txt
git add README.md