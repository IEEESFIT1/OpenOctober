public int p;
public List<String> answers;

class generateParentheses{
  public List<String> generateParenthesis(int p) {
      answers = new ArrayList<String>();
      this.p = p;
      helper( 1, 0, "(", "" ); //first has to be "("
      return answers;
  }

  public void helper( int leftP, int rightP, String s, String curr ){
      curr += s ;

      if( leftP == p && rightP == p ){
          answers.add( curr );
          return;
      }

      // The idea is the leftP always more than or equal to rightP.
      if( leftP < rightP || leftP > p || rightP > p ) return;

      helper( leftP +1, rightP, "(", curr );
      helper( leftP, rightP +1, ")", curr );

  }
}
