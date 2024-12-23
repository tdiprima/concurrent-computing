#!/bin/bash
# The tree utility program displays the directory structure

cd "$HOME/github/exploringBB/extras/cmake/student"


platform='unknown'
unamestr=`uname`
if [[ "$unamestr" == 'Linux' ]]; then
   tree
elif [[ "$unamestr" == 'Darwin' ]]; then
	# weird. can't find tree from script.
	# tree
    find . -print | sed -e 's; [^/]*/;|____;g;s;____|; |;g'
fi

# Temporary failure resolving 'us.archive.ubuntu.com'
# Check your network connection :)
