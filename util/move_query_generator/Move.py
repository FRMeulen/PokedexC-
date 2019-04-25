#	Project:	PokedexC++.
#	Move.py	--	Object containing information for a single move.
#	Revisions:
#	2019-04-25	--	F.R. van der Meulen	--	Created.

#	Imports.
import Query

class Move:
	#	__init__	--	Constructor for Move object.
	#	Parameters:
	#		move_type	--	Method move is learned by.
	#		move_name	--	Move name.
	#		move_data	--	Extra data for move.
	def __init__(self, move_type, move_name, move_data=None):
		self.move_type = move_type
		self.move_name = move_name
		self.move_data = move_data

	#	to_string	--	Converts Move object to string.
	#	Parameters:	none.
	#	Returns:	string.
	def to_string(self):
		if self.move_type == "level":
			move_string = "Move: {}, learned at level {}.".format(self.move_name, self.move_data)
		elif self.move_type == "tm":
			move_string = "Move: {}, learned by tm {}.".format(self.move_name, self.move_data)
		elif self.move_type == "egg":
			move_string = "Move: {}, learned by hatching.".format(self.move_name)
		elif self.move_type == "tutor":
			move_string = "Move: {}, learned by tutor.".format(self.move_name)
		else:
			move_string = "INVALID MOVE TYPE"
