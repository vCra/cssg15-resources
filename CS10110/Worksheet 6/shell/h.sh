me="$(basename "$(test -L "$0" && readlink "$0" || echo "$0")")"
echo $me
