class RabinKarpSearch{
  private int prime = 101;
 
  public int patternSearch(char[] text, char[] pattern) {
    int m = pattern.length;
    int n = text.length;

    long patternHash = createHash(pattern, m-1);
    long textHash = createHash(text, m-1);

    for(int i=1; i<=n-m+1; i++){
      if(patternHash == textHash && checkEqual(text, i-1, i+m-2, pattern, 0, m-1)){
        return i-1;
      }
      if(i < n-m+1){
        textHash = recalculateHash(text, i-1, i+m-1, textHash, m);
      }
    }
    return -1;
  }

  private long recalculateHash(char[] str, int oldIndex,int newIndex, long oldHash, int patternLen) {
    long newHash = oldHash - str[oldIndex];
    newHash = newHash/prime;
    newHash += str[newIndex]*Math.pow(prime, patternLen - 1);
    return newHash;
  }
  
  private long createHash(char[] str, int end) {
    long hash = 0;
    for(int i=0; i<=end; i++){
      hash += str[i]*Math.pow(prime, i);
    }
    return hash;
  }
  
  private boolean checkEqual(char str1[], int start1, int end1, char str2[], int start2, int end2){
    if(end1-start1 != end2 - start2){
      return false;
    }
    while(start1 <= end1 && start2 <= end2){
      if(str1[start1] != str2[start2]){
        return false;
      }
      start1++;
      start2++;
    }
    return true;
  }
}



public class Rabin_Karp {
	public static void main(String args[])
	{
    RabinKarpSearch rks = new RabinKarpSearch();
		System.out.print(rks.patternSearch("OmkarGaikwad".toCharArray(), "aik".toCharArray()));
	}
}
