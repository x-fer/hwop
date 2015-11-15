# this script assumes that you have working checkout of hwop-engine repos.
# in ../hwop-engine/.
# you can test your engine with ../hwop-engine/hwop test

# pull and make sure on master.
git checkout master
git pull

if which dot > /dev/null; then
  echo -ne
else
  echo "Install graphviz. (which dot failed)."
  exit 1
fi

outdir=../__hwop_html

[ -f deploy.sh ] || ( echo "must be in root hwop dir."; exit 1; )

../hwop-engine/hwop build --src=wiki --dst=$outdir

git stash > /dev/null

  git checkout gh-pages &> /dev/null
  git pull --rebase &> /dev/null
  rm -rf * > /dev/null
  cp -r $outdir/* .
  git add --all > /dev/null
  git commit --message='gh-pages updated.' && git push origin HEAD:gh-pages
  git checkout master &> /dev/null

git stash pop > /dev/null
