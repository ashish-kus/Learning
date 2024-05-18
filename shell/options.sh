#!/bin/bash


echo "nandu"
while getopts ":d:" opt; do
    case $opt in
        d)
            echo $OPTARG
            ;;
        \?)
            echo "Handle invalid option"
            ;;
        :)
            echo  "Handle option that requires an argument but none provided"
            ;;
    esac
done
shift $((OPTIND - 1))

echo "bandu"

# if [ $# -eq 0 ]; then
#   echo "Usage: $0 [git-url=<URL>] [directory=<path>]"
#   exit 1
# fi

# # Parse command-line arguments
# for arg in "$@"; do
#   case $arg in
#     git-url=*)
#       git_url="${arg#*=}"
#       ;;
#     directory=*)
#       directory="${arg#*=}"
#       ;;
#     *)
#       echo "Unknown argument: $arg"
#       exit 1
#       ;;
#   esac
# done



# echo  git_url $git_url
# echo DIR = $directory
