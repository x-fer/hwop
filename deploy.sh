# this script assumes that you have working checkout of hwop-engine repos.
# in ../hwop-engine/.
# you can test your engine with ../hwop-engine/hwop test

../hwop-engine/hwop build --src=wiki --dst=/tmp/hwop-output
git checkout -b gh-pages
rm -rf *
cp -r /tmp/hwop-output/* .
git add --all
git commit -a -m 'gh-pages updated.'
git push
git checkout master
