# add entensions as needed for the languages you use
# *.cpp *.py *.c *.c# *.cc *.cs *.cxx *.go *.hs *.java *.js *.m *.pas *.php *.pl *.rb
codePathPrefix="../code/"
ReadmePath="../README.md"
echo $codePathPrefix*.cpp $codePathPrefix*.py > temp.txt
python3 seperateNames.py temp.txt > filenames.txt
cat README.template > $ReadmePath
echo "| Problem | Language | " >> $ReadmePath
echo "|:-------:|:--------:| " >> $ReadmePath
python3 createReadme.py filenames.txt >> $ReadmePath
rm filenames.txt
rm temp.txt
git add $ReadmePath