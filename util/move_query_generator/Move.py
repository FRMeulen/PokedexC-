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
	def __init__(self, move_data, learn_method):
		self.move_data = move_data
		if learn_method == 1:
			self.learn_method = "Level"
		elif learn_method == 2:
			self.learn_method = "TM"
		elif learn_method == 3:
			self.learn_method = "Egg"
		elif learn_method == 4:
			self.learn_method = "Tutor"
		else:
			print("Error: learn_method not found!")

	#	to_string	--	Converts Move object to string.
	#	Parameters:	none.
	#	Returns:	string.
	def to_string(self):
		str_move = "Move: {}, learned by {}.".format(self.move_data, self.learn_method)
		return str_move
	#	End to_string().
