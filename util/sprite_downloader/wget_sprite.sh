#!/bin/sh
pokemon=$1
url="https://assets.pokemon.com/assets/cms2/img/pokedex/full/${pokemon}.png"
command echo "Getting sprite for: ${pokemon}"
command wget "${url}"
command mv "./${pokemon}.png" "../res/sprites/#${pokemon}.png"
command convert "../res/sprites/#${pokemon}.png" -resize 384x384\! -quality 100 "../res/sprites/#${pokemon}.png"
command cp "../res/sprites/#${pokemon}.png" "../res/icons/#${pokemon}.png"
command convert "../res/icons/#${pokemon}.png" -resize 96x96\! -quality 100 "../res/icons/#${pokemon}.png"