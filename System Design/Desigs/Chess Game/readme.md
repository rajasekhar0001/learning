Game Flow
1. Bring the board 8 x 8
2. Place the pawns
3. Bring the players
4. Let allow, player with white move First
5. Check is there any possibility for check, If so opponent has to protect King from check
6. Let Black take move
7. Check is there any possibility for check, If so opponent has to protect King from check
8. If there is no possibility to protect King, Game won
9. Else, if only one pawn left in any one of the team, if no check mate for 21 times, considered as Game **DRAW**

Design Patterns required:
Singleton Pattern -> for board and Game
Factory Pattern -> for pieces creation
Strategy Pattern -> for piece movement (like king, queen, etc)
State Pattern -> Managing Game state (active, white win, black win, stalemate (draw))

