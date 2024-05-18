#!/usr/bin/env bash

cup() {
  checkupdates --nocolor
  pacman -Qm | aur vercmp
}

cup | wc -l 
