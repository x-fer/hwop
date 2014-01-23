../hwop-engine/hwop build --src=wiki --dst=/tmp/hwop-output
git checkout -b gh-pages
rm -rf *
cp -r /tmp/hwop-output/* .
git commit -a -m 'gh-pages updated.'
