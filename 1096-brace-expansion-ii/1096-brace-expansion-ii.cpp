class Solution {
public:

    set<string> parse(string& s, int& i) {

        set<string> result;
        set<string> current = {""};

        while (i < s.size() && s[i] != '}') {

            if (s[i] == ',') {
                // Union
                i++;

                set<string> next = parse(s, i);

                result.insert(next.begin(), next.end());
            }

            else {

                set<string> part;

                if (s[i] == '{') {
                    i++;  // skip {

                    part = parse(s, i);

                    i++;  // skip }
                }

                else {
                    part.insert(string(1, s[i]));
                    i++;
                }

                // Concatenation
                set<string> temp;

                for (string a : current) {
                    for (string b : part) {
                        temp.insert(a + b);
                    }
                }

                current = temp;
            }
        }

        result.insert(current.begin(), current.end());

        return result;
    }

    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> ans = parse(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};