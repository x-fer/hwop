# this script assumes that you have working checkout of hwop-engine repos.
# in ../hwop-engine/.
# you can test your engine with ../hwop-engine/hwop test

# if error occurs stop.
set -e

../hwop-engine/hwop build --src=wiki --dst=/tmp/hwop-output
git checkout gh-pages
rm -rf *
cp -r /tmp/hwop-output/* .
git add --all
git commit -m 'gh-pages updated.'
git push origin HEAD:gh-pages
git checkout master
rm -rf /tmp/hwop-output
