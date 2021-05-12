#!/bin/bash

# Simple script for publishing libraries
BART_PREFIX="BartOS-*"

for f in * ; do
    FILE_NAME="$f";

    if [[ -d $FILE_NAME ]] && [[ $FILE_NAME == $BART_PREFIX ]]; then
      echo "Publish library for: $FILE_NAME";
      ( cd $FILE_NAME && pio package publish ) &
    fi;
done
