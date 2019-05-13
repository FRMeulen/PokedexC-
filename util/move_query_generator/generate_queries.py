#	Project:	PokedexC++.
#	generate_queries.py	--	Auxiliary script to generate SQL-queries.
#	Revisions:
#	2018-12-19	--	F.R. van der Meulen	--	Created.
#	2019-01-31	--	F.R. van der Meulen	--	Major functionality rework.

#	Imports.
import Query
import Move
import Moveset

#	Stored sets.
filtered_lines = []
prased_movesets = []
moves = []
queries = []

#	read_file	--	Reads file from path and returns read text.
#	Parameters:
#		filename	--	Name of file to read.
#	Returns:	string.
def read_file(filename):
	file = open(filename)
	read_text = file.read()
	file.close()
	return read_text
#	End read_file().

#	filter_lines	--	Filters out empty lines.
#	Parameters:
#		txt	--	Raw text to be filtered.
#	Returns:	list of strings.
def filter_lines(txt):
	lastchar = ""
	filtered_text = ""
	for i in range(0, len(txt)):
		if not (txt[i] == '\n' and txt[i - 1] == '\n' and i != 0):
			filtered_text += txt[i]

	line = ""
	lines = []
	for char in filtered_text:
		if char != '\n':
			line += char
		else:
			lines.append(line)
			line = ""

	return lines
#	End filter_lines().

#	parse_moves	--	Splits raw text into Move objects.
#	Parameters:
#		text	--	Raw text to parse.
#	Returns:	list of Moveset objects.
def parse_movesets(lines):
	movesets = []
	for i in range(0, int(len(lines) / 5)):
		moveset = Moveset.Moveset(lines[i * 5],lines[i * 5 + 1], lines[i * 5 + 2], lines[i * 5 + 3], lines[i * 5 + 4])
		movesets.append(moveset)

	return movesets
#	End parse_moves().

#	Program sequence.
parsed_movesets = parse_movesets(filter_lines(read_file("move_add.txt")))
i = 1
for moveset in parsed_movesets:
	moveset.parse_moves()