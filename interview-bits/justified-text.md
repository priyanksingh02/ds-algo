```cpp

vector<string> Solution::fullJustify(vector<string> &A, int B) {
    vector<vector<string>> words;
    int linesize = 0;
    vector<string> line;
    for(int i= 0; i < A.size(); ++i) {
        if(line.empty()) {
            line.push_back(A[i]);
            linesize += A[i].size();
        }
        else {
            int req = A[i].size() + 1;
            if(req + linesize <= B) {
                line.push_back(A[i]);
                linesize += req;
            }
            else {
                words.push_back(line);
                line.clear();
                i--;
                linesize = 0;
            }
        }
    }
    if(!line.empty()) {
        words.push_back(line);
    }
    vector<string> ans;
    for(int i = 0; i < words.size(); ++i) {
        line = words[i];
        string text;
        if(i + 1 == words.size() or line.size() == 1) { // last line
            for(auto & s: line) {
                text += s + " ";
            }
            text.pop_back();
            int rem = B - (int)text.size();
            if(rem > 0) {
                text += string(rem, ' ');
            }
            assert(rem >= 0);
        }
        else {
            int total = 0;
            for(auto & word: line) {
                total += word.size();
            }
            int space = B - total;
            int block = (int)line.size() - 1;
            int left = space%block;
            int fill = space/block;
            for(int i = 0; i < left; ++i) {
                text += line[i] + string(fill+1, ' ');
            }
            for(int i = left; i < line.size(); ++i) {
                text += line[i];
                if(i+1 != line.size())
                    text+= string(fill, ' ');
            }
        }
        ans.push_back(text);
    }
    return ans;
}
```

```cpp
vector<string> Solution::fullJustify(vector<string> &A, int B) {
    vector<string> ans;
    int pos = 0;
    while(pos < A.size()) {
        vector<string> line;
        int linesize = 0;
        bool lastline = true;
        while(pos < A.size()) {
            int space = !line.empty();
            if(linesize + A[pos].size() + space <= B) {
                line.push_back(A[pos++]);
                linesize += line.back().size();
                linesize += space;
            }
            else {
                lastline = false;
                break;
            }
        }
        if(lastline) {
            string final_line;
            for(int i = 0; i < line.size(); ++i) {
                if(i != 0)
                    final_line += " ";
                final_line += line[i];
            }
            final_line += string(B-final_line.size(),' ');
            ans.push_back(final_line);
            continue;
        }
        int no_of_space = (int)line.size() - 1;
        if(no_of_space < 0)
            throw "negative no_of_space";
        int spare_space = B - linesize;
        int space_count = 1;
        int extra_on_left = 0;
        if(no_of_space != 0 && spare_space > 0) {
            space_count = spare_space/no_of_space+1;
            extra_on_left = spare_space%no_of_space;
        }
        // cout << ans.size() + 1 << " ";
        // cout << "spare_space = " << spare_space << " ";
        // cout << "space_count = " << space_count <<  " ";
        // cout << "extra_on_left = " << extra_on_left << endl;
        string final_line;
        for(int i = 0; i < line.size(); ++i) {
            string print_space;
            if(i != 0) {
                if(extra_on_left > 0) {
                    extra_on_left--;
                    
                    print_space += string(space_count + 1, ' ');
                }
                else {
                    print_space += string(space_count,' ');
                }
            }
            // cout << "Adding space (" << print_space << ")" << endl;
            final_line+= print_space + line[i];
        }
        if(final_line.size() < B) {
            final_line += string(B-final_line.size(),' ');
        }
        ans.push_back(final_line);
    }
    // cout << "No of lines = " << ans.size() << endl;
    return ans;
    
}
```
