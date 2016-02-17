#!/bin/bash

case $# in
0|1) echo "Usage " $(basename $0) " <oldext> <newext>"; exit 1;;
esac

for f in *.$1
do
  echo $f
  base=$(basename $f .$1)
  mv $f $base.$2
done
