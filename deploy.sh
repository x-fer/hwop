# this script assumes that you have working checkout of hwop-engine repos.
# in ../hwop-engine/.
# you can test your engine with ../hwop-engine/hwop test

outdir=../__hwop_html

[ -f deploy.sh ] || ( echo "must be in root hwop dir."; exit 1; )

../hwop-engine/hwop build --src=wiki --dst=$outdir

git stash > /dev/null

  git checkout gh-pages &> /dev/null
  rm -rf * > /dev/null
  cp -r $outdir/* .
  git add --all > /dev/null
  git commit --message='gh-pages updated.' && git push origin HEAD:gh-pages
  git checkout master &> /dev/null

git stash pop > /dev/null
