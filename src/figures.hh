// Black Textures
sf::Texture b_pawn_t;
sf::Texture b_king_t;
sf::Texture b_queen_t;
sf::Texture b_rook_t;
sf::Texture b_knight_t;
sf::Texture b_bishop_t;
// White Textures
sf::Texture w_pawn_t;
sf::Texture w_king_t;
sf::Texture w_queen_t;
sf::Texture w_rook_t;
sf::Texture w_knight_t;
sf::Texture w_bishop_t;

// Loading File for Textures Black
b_pawn_t.loadFromFile("Assets/b_pawn.png");
b_king_t.loadFromFile("Assets/b_king.png");
b_queen_t.loadFromFile("Assets/b_queen.png");
b_rook_t.loadFromFile("Assets/b_rook.png");
b_knight_t.loadFromFile("Assets/b_knight.png");
b_bishop_t.loadFromFile("Assets/b_bishop.png");
// Loading File for Textures White  
w_pawn_t.loadFromFile("Assets/w_pawn.png");
w_king_t.loadFromFile("Assets/w_king.png");
w_queen_t.loadFromFile("Assets/w_queen.png");
w_rook_t.loadFromFile("Assets/w_rook.png");
w_knight_t.loadFromFile("Assets/w_knight.png");
w_bishop_t.loadFromFile("Assets/w_bishop.png");
  
// Black Sprites
sf::Sprite b_pawn(b_pawn_t);
sf::Sprite b_king(b_king_t);
sf::Sprite b_queen(b_queen_t);
sf::Sprite b_rook(b_rook_t);
sf::Sprite b_knight(b_knight_t);
sf::Sprite b_bishop(b_bishop_t);
// White Sprites
sf::Sprite w_pawn(w_pawn_t);
sf::Sprite w_king(w_king_t);
sf::Sprite w_queen(w_queen_t);
sf::Sprite w_rook(w_rook_t);
sf::Sprite w_knight(w_knight_t);
sf::Sprite w_bishop(w_bishop_t);

std::array<sf::Sprite, 6> b_sprites = { b_pawn, b_king, b_queen, b_rook, b_knight, b_bishop };
std::array<sf::Sprite, 6> w_sprites = { w_pawn, w_king, w_queen, w_rook, w_knight, w_bishop };

