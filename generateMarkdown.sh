# add entensions as needed for the languages you use
# *.cpp *.py *.c *.c# *.cc *.cs *.cxx *.go *.hs *.java *.js *.m *.pas *.php *.pl *.rb
echo *.cpp *.py > temp.txt
python3 seperateNames.py.ignore temp.txt > filenames.txt
cat README.template > README.md
echo "| Problem | Language | " >> README.md
echo "|:-------:|:--------:| " >> README.md
python3 createReadme.py.ignore filenames.txt >> README.md
rm filenames.txt
rm temp.txt
git add README.md