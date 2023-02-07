#!/bin/bash
# http://derekmolloy.ie/hello-world-introductions-to-cmake/

echo "### cmake version (for CMakeLists.txt) ###"
cmake -version

cd $HOME/github
# sudo apt-get install git
# git clone https://github.com/derekmolloy/exploringBB.git

goto_dir="exploringBB/extras/cmake/helloworld/"

platform='unknown'
unamestr=`uname`
if [[ "$unamestr" == 'Linux' ]]; then
   echo ""
   echo "### Go to: $goto_dir ###"
   echo ""
elif [[ "$unamestr" == 'Darwin' ]]; then
   open "$goto_dir"
fi

cd $goto_dir

cmake .
make
./hello
