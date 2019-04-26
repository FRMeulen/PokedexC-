#	Project:	PokedexC++.
#	generate_queries.py	--	Auxiliary script to generate SQL-queries.
#	Revisions:
#	2018-12-19	--	F.R. van der Meulen	--	Created.
#	2019-01-31	--	F.R. van der Meulen	--	Major functionality rework.

#	Imports.
import Query
import Moveset

#	Stored sets.
movesets = []
moves = []
queries = []

#	Stored variables.
raw_text = ""

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

#	parse_movesets	--	Splits raw text into Moveset objects.
#	Parameters:
#		text	--	Raw text to parse.
#	Returns:	list of Moveset objects.
def parse_movesets(text):
	sets = []
	lines = []
	line = ""
	for char in text:
		if char != '\n':
			line += char
		else:
			if len(line) > 0:
				lines.append(line)
				line = ""
			else:
				moves = Moveset.Moveset(lines[0], lines[1], lines[2], lines[3], lines[4])
				sets.append(moves)
				lines = []

	return sets
#	End parse_movesets().

#	print_all_movesets	--	Debugs all parsed Moveset objects.
#	Parameters:	none.
#	Returns:	nothing.
def print_all_movesets():
	if len(movesets) == 0:
		print("NO EXISTING MOVESETS")
	else:
		for i in range(0, len(movesets)):
			print("----------[MOVESET {}]----------".format(i))
			print(movesets[i].to_string())
			print()
#	End print_all_movesets.

#	Program sequence.
raw_text = read_file("move_add.txt")
movesets = parse_movesets(raw_text)

#	Debug.
for i in range(0, len(movesets)):
	print("-----[MOVESET {}]-----".format(i))
	print(movesets[i].to_string())
	print()

	temp_moves = movesets[i].parse_moves()
	for move in temp_moves:
		moves.append(move)
