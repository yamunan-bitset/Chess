pieces.clear();

for (unsigned int i = 0; i < b_sprites.size(); i++)
  pieces.push_back(ChessPiece(window, b_sprites[i]));
for (unsigned int i = 0; i < w_sprites.size(); i++)
  pieces.push_back(ChessPiece(window, w_sprites[i]));

