// Loading File for Textures Black
std::string b_pawn   = "Assets/b_pawn.png";
std::string b_king   = "Assets/b_king.png";
std::string b_queen  = "Assets/b_queen.png";
std::string b_rook   = "Assets/b_rook.png";
std::string b_knight = "Assets/b_knight.png";
std::string b_bishop = "Assets/b_bishop.png";
// Loading File for Textures White  
std::string w_pawn   = "Assets/w_pawn.png";
std::string w_king   = "Assets/w_king.png";
std::string w_queen  = "Assets/w_queen.png";
std::string w_rook   = "Assets/w_rook.png";
std::string w_knight = "Assets/w_knight.png";
std::string w_bishop = "Assets/w_bishop.png";

std::array<std::string, 6> b_sprites = { b_pawn, b_king, b_queen, b_rook, b_knight, b_bishop };
std::array<std::string, 6> w_sprites = { w_pawn, w_king, w_queen, w_rook, w_knight, w_bishop };
std::vector<ChessPiece> pieces;

for (unsigned int i = 0; i < w_sprites.size(); i++)
  pieces.push_back(ChessPiece(window, w_sprites[i]));
for (unsigned int i = 0; i < b_sprites.size(); i++)
  pieces.push_back(ChessPiece(window, b_sprites[i]));
