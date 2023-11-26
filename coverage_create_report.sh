#!/bin/zsh

echo "Removing old report"
rm -r -f ./tests/coverage
mkdir ./tests/coverage

echo "Creating new report"
gcovr ./build/src -r ./src/cns --html --html-details -o ./tests/coverage/coverage.html