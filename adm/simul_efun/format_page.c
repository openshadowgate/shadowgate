varargs string format_page(string * items, int columns, int scrwidth, int vertical)
{
    int width, i, j, x;
    string ret;

    if (vertial) {
        return format_page_v(items, columns, scrwidth);
    }

    if (!columns) {
        columns = 2;
    }
    if (!scrwidth) {
        scrwidth = 72;
    }

    ret = "";
    width = scrwidth / columns;
    for (i = 0, x = sizeof(items); i < x; i += columns) {
        for (j = 0; j < columns; j++) {
            if (i + j >= x) {
                break;
            }
            ret += arrange_string(items[i + j], width);
        }
        ret += "\n";
    }
    return ret;
}

varargs string format_page_v(string* items, int columns, int scrwidth)
{

    int width;
    int i, j;
    int column_height;
    string ret = "";

    if (!columns) {
        columns = 2;
    }
    if (!scrwidth) {
        scrwidth = 72;
    }

    column_height = sizeof(items) / columns + sizeof(items) % columns;
    width = scrwidth / columns;

    for (j = 0; j < column_height; j++ )
    {
        for (i = 0; i < (columns); i++ )
        {
            if ((i * column_height + j) >= sizeof(items)) {
                break;
            }
            ret += arrange_string(items[i * column_height + j], width);
        }
        ret += "\n";

    }
    return ret;
}
