#!/bin/bash

echo "  Iter: $3"
echo "      $3 (Arguments): $* "
# SYNTAX./main  $NUM_ITER $OUTDIR/FILENAME.$ITER   $ITER (provided by xargs)
./main $1 $2.$3.txt $3
