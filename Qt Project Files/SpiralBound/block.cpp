#include "block.h"

Block::Block() { type = TYPE_TEXT; content = ""; }

// Author:       Matthew Morgan
// Init date:    02-12-2019
// Last Updated: 02-12-2019
short Block::getType() { return type; }

// Author:       Matthew Morgan
// Init date:    02-12-2019
// Last Updated: 02-12-2019
QString Block::getContent() { return content; }

// Author:       Matthew Morgan
// Init date:    02-12-2019
// Last Updated: 02-12-2019
void Block::setType(short p) {
    type = p;
}

// Author:       Matthew Morgan
// Init date:    02-12-2019
// Last Updated: 02-12-2019
void Block::setContent(QString con) { content = con; }
