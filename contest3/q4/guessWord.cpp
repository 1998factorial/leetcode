/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */

/**
	最多只能猜10次，当words里面有很多词的时候，很难猜到正确的词。
	所以我们每一次猜词的时候都要找到一个最“小众”的词。
	例：aaaaaa 与 aaaaab 有5个match
	每一个词与被选中的词有0～6之间的match，定义一个hash table T，
	T(n) = "words中与被选中的词match为n的个数"
	此时，我们的最佳选择为：max{T(n),n = 0..6} 最小的词。

	由于secret word 一定在words中，故和被我们选中的词存在match，
	所以，我们只保留与secret word match数相等的词，从而最大化每一轮
	淘汰掉的词的数量。


	"hbaczn"
["gaxckt","trlccr","jxwhkz","ycbfps","peayuf","yiejjw","ldzccp","nqsjoa","qrjasy","pcldos","acrtag","buyeia","ubmtpj","drtclz","zqderp","snywek","caoztp","ibpghw","evtkhl","bhpfla","ymqhxk","qkvipb","tvmued","rvbass","axeasm","qolsjg","roswcb","vdjgxx","bugbyv","zipjpc","tamszl","osdifo","dvxlxm","iwmyfb","wmnwhe","hslnop","nkrfwn","puvgve","rqsqpq","jwoswl","tittgf","evqsqe","aishiv","pmwovj","sorbte","hbaczn","coifed","hrctvp","vkytbw","dizcxz","arabol","uywurk","ppywdo","resfls","tmoliy","etriev","oanvlx","wcsnzy","loufkw","onnwcy","novblw","mtxgwe","rgrdbt","ckolob","kxnflb","phonmg","egcdab","cykndr","lkzobv","ifwmwp","jqmbib","mypnvf","lnrgnj","clijwa","kiioqr","syzebr","rqsmhg","sczjmz","hsdjfp","mjcgvm","ajotcx","olgnfv","mjyjxj","wzgbmg","lpcnbj","yjjlwn","blrogv","bdplzs","oxblph","twejel","rupapy","euwrrz","apiqzu","ydcroj","ldvzgq","zailgu","xgqpsr","wxdyho","alrplq","brklfk"]
10
**/
class Solution {
public:
	int match(string& a, string& b){
		int ret = 0,n = a.size();
		for(int i = 0; i < n; i++)
			ret += (a[i] == b[i]);
		return ret;
	}

	int cal(vector<string>& words, string& in){
		vector<int> mp(7,0);
		for(auto& word : words){
			++mp[match(word,in)];
		}
		return *max_element(mp.begin(),mp.end());
	}

    void findSecretWord(vector<string>& words, Master& master) {
    	for(int x = 0; x < 10; x++){ //at most 10 guesses
    		int max_m = 1 << 31 - 1, best_i = -1;
    		for(int i = 0; i < words.size(); i++){
    			int r = cal(words,words[i]);
    			if(r < max_m){
    				max_m = r;
    				best_i = i;
    			}
    		}
    		int result = master.guess(words[best_i]);
    		vector<string> next_round;
    		for(auto& word: words){
    			if(match(word,words[best_i]) == result)
    				next_round.push_back(word);
    		}
    		words = next_round;
    	}
    }
};


