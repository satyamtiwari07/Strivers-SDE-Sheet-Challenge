bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char>st;
    int n=expression.size();

    for(int x=0;x<n;x++){
      if (st.empty()) {
        if (expression[x] == '}' || expression[x] == ')' || expression[x] == ']') return false;
        st.push(expression[x]);
      } 
      else if (expression[x] == '}' and st.top()=='{') st.pop();
      else if (expression[x] == ')' and st.top()=='(') st.pop();
      else if (expression[x] == ']' and st.top()=='[') st.pop();
      else st.push(expression[x]);
    }
    return st.empty();
}
