#!/usr/bin/env bash


clone_REPO() {
  repo=$1
  echo $repo
    
}

main() {
  DOTFILE_GIT_REPO=${DOTFILE_GIT_REPO:-${1}}
  echo "$DOTFILE_GIT_REPO"

  clone_REPO "banda"
}

main "$@"
