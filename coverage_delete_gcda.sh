#!/bin/zsh

echo "Deleting old *.gcda files"
find $1 -name '*.gcda' -delete