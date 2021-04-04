#pragma strict_types
#define strstr                      strsrch
#define raise_error                 error
#define member(x, y)                member_array(y, x)
#define to_string(x)                ("" + (x))

#define array                       *

#define JSON_DECODE_PARSE_TEXT      0
#define JSON_DECODE_PARSE_POS       1
#define JSON_DECODE_PARSE_LINE      2
#define JSON_DECODE_PARSE_CHAR      3

#define JSON_DECODE_PARSE_FIELDS    4

private void json_decode_parse_next_char(mixed array parse) {
    parse[JSON_DECODE_PARSE_POS]++;
    parse[JSON_DECODE_PARSE_CHAR]++;
}

private void json_decode_parse_next_chars(mixed array parse, int num) {
    parse[JSON_DECODE_PARSE_POS] += num;
    parse[JSON_DECODE_PARSE_CHAR] += num;
}

private void json_decode_parse_next_line(mixed array parse) {
    parse[JSON_DECODE_PARSE_POS]++;
    parse[JSON_DECODE_PARSE_LINE]++;
    parse[JSON_DECODE_PARSE_CHAR] = 1;
}

private int json_decode_hexdigit(int ch) {
    switch(ch) {
    case '0'    :
        return 0;
    case '1'    :
    case '2'    :
    case '3'    :
    case '4'    :
    case '5'    :
    case '6'    :
    case '7'    :
    case '8'    :
    case '9'    :
        return ch - '0';
    case 'a'    :
    case 'A'    :
        return 10;
    case 'b'    :
    case 'B'    :
        return 11;
    case 'c'    :
    case 'C'    :
        return 12;
    case 'd'    :
    case 'D'    :
        return 13;
    case 'e'    :
    case 'E'    :
        return 14;
    case 'f'    :
    case 'F'    :
        return 15;
    }
    return -1;
}

private varargs int json_decode_parse_at_token(mixed array parse, string token, int start) {
    int i, j;
    for(i = start, j = strlen(token); i < j; i++)
        if(parse[JSON_DECODE_PARSE_TEXT][parse[JSON_DECODE_PARSE_POS] + i] != token[i])
            return 0;
    return 1;
}

private varargs void json_decode_parse_error(mixed array parse, string msg, int ch) {
    if(ch)
        msg = sprintf("%s, '%c'", msg, ch);
    msg = sprintf("%s @ line %d char %d\n", msg, parse[JSON_DECODE_PARSE_LINE], parse[JSON_DECODE_PARSE_CHAR]);
    raise_error(msg);
}

private mixed json_decode_parse_object(mixed array parse) {
    mapping out = ([]);
    int done = 0;
    mixed key, value;
    int found_non_whitespace, found_sep, found_comma;
    json_decode_parse_next_char(parse);
    if(parse[JSON_DECODE_PARSE_TEXT][parse[JSON_DECODE_PARSE_POS]] == '}') {
        done = 1;
        json_decode_parse_next_char(parse);
    }
    while(!done) {
        found_non_whitespace = 0;
        while(!found_non_whitespace) {
            switch(parse[JSON_DECODE_PARSE_TEXT][parse[JSON_DECODE_PARSE_POS]]) {
            case 0      :
                json_decode_parse_error(parse, "Unexpected end of data");
            case ' '    :
            case '\t'   :
            case '\r'   :
                json_decode_parse_next_char(parse);
                break;
            case 0x0c   :
            case '\n'   :
                json_decode_parse_next_line(parse);
                break;
            default     :
                found_non_whitespace = 1;
                break;
            }
        }
        key = json_decode_parse_string(parse);
        found_sep = 0;
        while(!found_sep) {
            int ch = parse[JSON_DECODE_PARSE_TEXT][parse[JSON_DECODE_PARSE_POS]];
            switch(ch) {
            case 0      :
                json_decode_parse_error(parse, "Unexpected end of data");
            case ':'    :
                found_sep = 1;
                json_decode_parse_next_char(parse);
                break;
            case ' '    :
            case '\t'   :
            case '\r'   :
                json_decode_parse_next_char(parse);
                break;
            case 0x0c   :
            case '\n'   :
                json_decode_parse_next_line(parse);
                break;
            default     :
                json_decode_parse_error(parse, "Unexpected character", ch);
            }
        }
        value = json_decode_parse_value(parse);
        found_comma = 0;
        while(!found_comma && !done) {
            int ch = parse[JSON_DECODE_PARSE_TEXT][parse[JSON_DECODE_PARSE_POS]];
            switch(ch) {
            case 0      :
                json_decode_parse_error(parse, "Unexpected end of data");
            case ','    :
                found_comma = 1;
                json_decode_parse_next_char(parse);
                break;
            case '}'    :
                done = 1;
                json_decode_parse_next_char(parse);
                break;
            case ' '    :
            case '\t'   :
            case '\r'   :
                json_decode_parse_next_char(parse);
                break;
            case 0x0c   :
            case '\n'   :
                json_decode_parse_next_line(parse);
                break;
            default     :
                json_decode_parse_error(parse, "Unexpected character", ch);
            }
        }
        out[key] = value;
    }
    return out;
}

private mixed json_decode_parse_array(mixed array parse) {
    mixed array out = ({});
    int done = 0;
    int found_comma;
    json_decode_parse_next_char(parse);
    if(parse[JSON_DECODE_PARSE_TEXT][parse[JSON_DECODE_PARSE_POS]] == ']') {
        done = 1;
        json_decode_parse_next_char(parse);
    }
    while(!done) {
        mixed value = json_decode_parse_value(parse);
        found_comma = 0;
        while(!found_comma && !done) {
            int ch = parse[JSON_DECODE_PARSE_TEXT][parse[JSON_DECODE_PARSE_POS]];
            switch(ch) {
            case 0      :
                json_decode_parse_error(parse, "Unexpected end of data");
            case ','    :
                found_comma = 1;
                json_decode_parse_next_char(parse);
                break;
            case ']'    :
                done = 1;
                json_decode_parse_next_char(parse);
                break;
            case ' '    :
            case '\t'   :
            case '\r'   :
                json_decode_parse_next_char(parse);
                break;
            case 0x0c   :
            case '\n'   :
                json_decode_parse_next_line(parse);
                break;
            default     :
                json_decode_parse_error(parse, "Unexpected character", ch);
            }
        }
        out += ({ value });
    }
    return out;
}

private varargs mixed json_decode_parse_string(mixed array parse, int initiator_checked) {
    int from, to, esc_state, esc_active;
    string out;
    if(!initiator_checked) {
        int ch = parse[JSON_DECODE_PARSE_TEXT][parse[JSON_DECODE_PARSE_POS]];
        if(!ch)
            json_decode_parse_error(parse, "Unexpected end of data");
        if(ch != '"')
            json_decode_parse_error(parse, "Unexpected character", ch);
    }
    json_decode_parse_next_char(parse);
    from = parse[JSON_DECODE_PARSE_POS];
    to = -1;
    esc_state = 0;
    esc_active = 0;
    while(to == -1) {
        switch(parse[JSON_DECODE_PARSE_TEXT][parse[JSON_DECODE_PARSE_POS]]) {
        case 0          :
            json_decode_parse_error(parse, "Unexpected end of data");
        case '\\'       :
            esc_state = !esc_state;
            break;
        case '"'        :
            if(esc_state) {
                esc_state = 0;
                esc_active++;
            } else {
                to = parse[JSON_DECODE_PARSE_POS] - 1;
            }
            break;
        default         :
            if(esc_state) {
                esc_state = 0;
                esc_active++;
            }
            break;
        }
        json_decode_parse_next_char(parse);
    }
    out = parse[JSON_DECODE_PARSE_TEXT][from .. to];
    if(esc_active) {
        if(member(out, '"') != -1)
            out = replace_string(out, "\\\"", "\"");
        if(strstr(out, "\\b") != -1)
            out = replace_string(out, "\\b", "\b");
        if(strstr(out, "\\f") != -1)
            out = replace_string(out, "\\f", "\x0c");
        if(strstr(out, "\\n") != -1)
            out = replace_string(out, "\\n", "\n");
        if(strstr(out, "\\r") != -1)
            out = replace_string(out, "\\r", "\r");
        if(strstr(out, "\\t") != -1)
            out = replace_string(out, "\\t", "\t");
        if(strstr(out, "\\u") != -1) {
            string array parts = explode(out, "\\u");
            int entries = sizeof(parts) * 2 - 1;
            string array proc = allocate(entries);
            int i, j;
            proc[0] = parts[0];
            for(i = 1, j = sizeof(parts); i < j; i++) {
                string part = parts[i];
                int array nybbles = allocate(4);
                int array bytes = allocate(2);
                for(int k = 0; k < 4; k++)
                    if((nybbles[k] = json_decode_hexdigit(part[k])) == -1)
                        json_decode_parse_error(parse, "Invalid hex digit", part[k]);
                bytes[0] = (nybbles[0] << 4) | nybbles[1];
                bytes[1] = (nybbles[2] << 4) | nybbles[3];
                if(member(bytes, 0) != -1)
                    bytes -= ({ 0 });
                proc[i * 2 - 1] = sprintf("%@c", bytes);
                proc[i * 2] = part[4..];
            }
            out = implode(proc, "");
        }
        if(member(out, '/') != -1)
            out = replace_string(out, "\\/", "/");
        if(member(out, '\\') != -1)
            out = replace_string(out, "\\\\", "\\");
    }
    return out;
}

private mixed json_decode_parse_number(mixed array parse) {
    int from = parse[JSON_DECODE_PARSE_POS];
    int to = -1;
    int dot = -1;
    int exp = -1;
    int first_ch = parse[JSON_DECODE_PARSE_TEXT][parse[JSON_DECODE_PARSE_POS]];
    int ch;
    string number;
    switch(first_ch) {
    case '-'            :
    {
        int next_ch = parse[JSON_DECODE_PARSE_TEXT][parse[JSON_DECODE_PARSE_POS] + 1];
        if(next_ch != '0')
            break;
        json_decode_parse_next_char(parse);
    }
    // Fallthrough
    case '0'            :
        json_decode_parse_next_char(parse);
        ch = parse[JSON_DECODE_PARSE_TEXT][parse[JSON_DECODE_PARSE_POS]];
        if(ch) {
            if(ch != '.')
                json_decode_parse_error(parse, "Unexpected character", ch);
            dot = parse[JSON_DECODE_PARSE_POS];
        }
        break;
    }
    json_decode_parse_next_char(parse);
    while(to == -1) {
        ch = parse[JSON_DECODE_PARSE_TEXT][parse[JSON_DECODE_PARSE_POS]];
        switch(ch) {
        case '.'        :
            if(dot != -1 || exp != -1)
                json_decode_parse_error(parse, "Unexpected character", ch);
            dot = parse[JSON_DECODE_PARSE_POS];
            json_decode_parse_next_char(parse);
            break;
        case '0'        :
        case '1'        :
        case '2'        :
        case '3'        :
        case '4'        :
        case '5'        :
        case '6'        :
        case '7'        :
        case '8'        :
        case '9'        :
            json_decode_parse_next_char(parse);
            break;
        case 'e'        :
        case 'E'        :
            if(exp != -1)
                json_decode_parse_error(parse, "Unexpected character", ch);
            exp = parse[JSON_DECODE_PARSE_POS];
            json_decode_parse_next_char(parse);
            break;
        case '-'        :
        case '+'        :
            if(exp == parse[JSON_DECODE_PARSE_POS] - 1) {
                json_decode_parse_next_char(parse);
                break;
            }
            // Fallthrough
        default         :
            to = parse[JSON_DECODE_PARSE_POS] - 1;
            if(dot == to || to < from)
                json_decode_parse_error(parse, "Unexpected character", ch);
            break;
        }
    }
    number = parse[JSON_DECODE_PARSE_TEXT][from .. to];
    if(dot != -1 || exp != -1)
        return to_float(number);
    else
        return to_int(number);
}

private mixed json_decode_parse_value(mixed array parse) {
    for(;;) {
        int ch = parse[JSON_DECODE_PARSE_TEXT][parse[JSON_DECODE_PARSE_POS]];
        switch(ch) {
        case 0          :
            json_decode_parse_error(parse, "Unexpected end of data");
        case '{'        :
            return json_decode_parse_object(parse);
        case '['        :
            return json_decode_parse_array(parse);
        case '"'        :
            return json_decode_parse_string(parse, 1);
        case '-'        :
        case '0'        :
        case '1'        :
        case '2'        :
        case '3'        :
        case '4'        :
        case '5'        :
        case '6'        :
        case '7'        :
        case '8'        :
        case '9'        :
            return json_decode_parse_number(parse);
        case ' '        :
        case '\t'       :
        case '\r'       :
            json_decode_parse_next_char(parse);
            break;
        case 0x0c       :
        case '\n'       :
            json_decode_parse_next_line(parse);
            break;
        case 't'        :
            if(json_decode_parse_at_token(parse, "true", 1)) {
                json_decode_parse_next_chars(parse, 4);
                return 1;
            } else {
                json_decode_parse_error(parse, "Unexpected character", ch);
            }
        case 'f'        :
            if(json_decode_parse_at_token(parse, "false", 1)) {
                json_decode_parse_next_chars(parse, 5);
                return 0;
            } else {
                json_decode_parse_error(parse, "Unexpected character", ch);
            }
        case 'n'        :
            if(json_decode_parse_at_token(parse, "null", 1)) {
                json_decode_parse_next_chars(parse, 4);
                return 0;
            } else {
                json_decode_parse_error(parse, "Unexpected character", ch);
            }
        default         :
            json_decode_parse_error(parse, "Unexpected character", ch);
        }
    }
}

private mixed json_decode_parse(mixed array parse) {
    mixed out = json_decode_parse_value(parse);
    for(;;) {
        int ch = parse[JSON_DECODE_PARSE_TEXT][parse[JSON_DECODE_PARSE_POS]];
        switch(ch) {
        case 0          :
            return out;
        case ' '        :
        case '\t'       :
        case '\r'       :
            json_decode_parse_next_char(parse);
            break;
        case 0x0c       :
        case '\n'       :
            json_decode_parse_next_line(parse);
            break;
        default         :
            json_decode_parse_error(parse, "Unexpected character", ch);
        }
    }
    return 0;
}

mixed json_decode(string text) {
    mixed array parse = allocate(JSON_DECODE_PARSE_FIELDS);
    parse[JSON_DECODE_PARSE_TEXT] = text;
    parse[JSON_DECODE_PARSE_POS] = 0;
    parse[JSON_DECODE_PARSE_CHAR] = 1;
    parse[JSON_DECODE_PARSE_LINE] = 1;
    return json_decode_parse(parse);
}

varargs string json_encode(mixed value, mixed array pointers) {
    if(undefinedp(value))
        return "null";
    if(intp(value) || floatp(value))
        return to_string(value);
    if(stringp(value)) {
        if(member(value, '"') != -1)
            value = replace_string(value, "\"", "\\\"");
        value = sprintf("\"%s\"", value);
        if(member(value, '\\') != -1) {
            value = replace_string(value, "\\", "\\\\");
            if(strstr(value, "\\\"") != -1)
                value = replace_string(value, "\\\"", "\"");
        }
        if(member(value, '\b') != -1)
            value = replace_string(value, "\b", "\\b");
        if(member(value, 0x0c) != -1)
            value = replace_string(value, "\x0c", "\\f");
        if(member(value, '\n') != -1)
            value = replace_string(value, "\n", "\\n");
        if(member(value, '\r') != -1)
            value = replace_string(value, "\r", "\\r");
        if(member(value, '\t') != -1)
            value = replace_string(value, "\t", "\\t");
        return value;
    }
    if(mapp(value)) {
        string out;
        int ix = 0;
        if(pointers) {
            // Don't recurse into circular data structures, output null for
            // their interior reference
            if(member(pointers, value) != -1)
                return "null";
            pointers += ({ value });
        } else {
            pointers = ({ value });
        }
        foreach(mixed k, mixed v in value) {
            // Non-string keys are skipped because the JSON spec requires that
            // object field names be strings.
            if(!stringp(k))
                continue;
            if(ix++)
                out = sprintf("%s,%s:%s", out, json_encode(k, pointers), json_encode(v, pointers));
            else
                out = sprintf("%s:%s", json_encode(k, pointers), json_encode(v, pointers));
        }
        return sprintf("{%s}", out);
    }
    if(arrayp(value))
        if(sizeof(value)) {
            string out;
            int ix = 0;
            if(pointers) {
                // Don't recurse into circular data structures, output null for
                // their interior reference
                if(member(pointers, value) != -1)
                    return "null";
                pointers += ({ value });
            } else {
                pointers = ({ value });
            }
            foreach(mixed v in value)
                if(ix++)
                    out = sprintf("%s,%s", out, json_encode(v, pointers));
                else
                    out = json_encode(v, pointers);
            return sprintf("[%s]", out);
        } else {
            return "[]";
        }
    // Values that cannot be represented in JSON are replaced by nulls.
    return "null";
}
