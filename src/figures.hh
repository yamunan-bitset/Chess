// Loading File for Textures Black
std::string b_pawn   = "data/assets/b_pawn.png";
std::string b_king   = "data/assets/b_king.png";
std::string b_queen  = "data/assets/b_queen.png";
std::string b_rook   = "data/assets/b_rook.png";
std::string b_knight = "data/assets/b_knight.png";
std::string b_bishop = "data/assets/b_bishop.png";
// Loading File for Textures White  
std::string w_pawn   = "data/assets/w_pawn.png";
std::string w_king   = "data/assets/w_king.png";
std::string w_queen  = "data/assets/w_queen.png";
std::string w_rook   = "data/assets/w_rook.png";
std::string w_knight = "data/assets/w_knight.png";
std::string w_bishop = "data/assets/w_bishop.png";

// 8 Pawns, 1 King, 1 Queen, 2 Rooks, 2 Knights, 2 Bishops
std::array<std::string, 16> b_sprites =
  { 	b_rook, b_knight, b_bishop, b_queen, b_king,
	b_bishop, b_knight, b_rook, b_pawn, b_pawn,
	b_pawn, b_pawn, b_pawn, b_pawn, b_pawn, b_pawn
  };
std::array<std::string, 16> w_sprites =
  { 	w_pawn, w_pawn, w_pawn, w_pawn, w_pawn, w_pawn, 
	w_pawn, w_pawn, w_rook, w_knight, w_bishop, 
	w_queen, w_king, w_bishop, w_knight, w_rook
  };

std::vector<ChessPiece> pieces;

for (unsigned int i = 0; i < b_sprites.size(); i++)
  pieces.push_back(ChessPiece(window, b_sprites[i]));
for (unsigned int i = 0; i < w_sprites.size(); i++)
  pieces.push_back(ChessPiece(window, w_sprites[i]));
