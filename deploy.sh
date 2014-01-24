# this script assumes that you have working checkout of hwop-engine repos.
# in ../hwop-engine/.
# you can test your engine with ../hwop-engine/hwop test

outdir=../__hwop_html

../hwop-engine/hwop build --src=wiki --dst=$outdir

git stash

  git checkout gh-pages
  git rm -r *
  cp -r $outdir/* .
  git add --all
  git commit --message='gh-pages updated.' && git push origin HEAD:gh-pages
  git checkout master

git stash pop
