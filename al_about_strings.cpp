// s1.front();// refrence to first character 'G'
// s1.back();//reference to last character 'e'
// s1.push_back('z');//append character
// s1.pop_back(); pop last character of string
// s1.begin() iterator to the beginning of the string
// s1.end() iterator pointing to the end of the string
// like vector, string doesn't have push_front() and pop_front()
// and because of support of iterator we can construct strings with iterators



// Ranged Access
// assign, append, insert, replace
// string s2="Dragon Land";
// s1.assign(s2);// this is same as s1=s2;
// benefit of assign function is it's flexibility
// s1.assign(s2,2,4);
// starting 2  length 4 then s1=agon
// s1.assign("Wisdom");//s1:Wisdom
// s1.assign("Wisdom",3);;// first three characters of wisdom s1:Wis
// s1.assign(s2,3);//Error
// s1.assign(3,'x');// s1="xxx"
// s1.assign({'a','b','c'}); //s1 :abc

// s1.append("def"); // s1: abc def
// s1.insert(2,// 2 is the start, "mountain", 4  4// is the number of charcters it will insert);
// s1 now becomes abmounc def
// s1.replace(2 ,5,s2,3,3) // 2 to 5 portion of s1 will be replaced with 3 to 3 portion of s2
// s1 is now abgon def
// s1.erase(1,4);  1 and 4 is starting and ending portion s1 is now a def
// first number parameter is start and second is generally the size
// s2.substr(2,4);// agon
// s1="abc";
// s1.c_str(); // convert string to c string s1="abc\0"
// s1.data();//abc
// s1.swap(s2);// 
//
//

//Member Function algorithms of string which are copy find and cmopare
//s1= "abcdefg";
//char buf[20];
//size_t len=s1.copy(buf,3);
////buf contains "abc" and len="3"
//len =s1.copy(buf,4,2);
//copy a portion of s1 // buf: cdef len =4
//s1="If a job is worth doing , it's worth doing well";
//size_t found = s1.find("doing");
//It will find the string "doing" in s1 and returns the position where it is found
//found=s1.find("doing", 20);// this starts searching "doing" at 20
//found==35
//found =s1.find("doing well", 0,5); // doing well at 0 and only look at five characters
//found= s1.find_first_of("doing"); //search first character of s1 which 
//found=s1.find_first_of("doing",10);//found==12
//found=s1.find_first_of("doing",10,1); // found ==17
//found=s1.find_last_of("doing") //found=39
//found=s1.find_first_not_of("doing");//found==0
//found=s1.find_last_not_of("doing");//found==44
//
//s1.compare(s2);//reutrn positive if (s1>s2); and negative if(s1<s2) ; and 0 if (s1==s2)
//if (s1>s2)
//{
//      std::cout<<"Do something"<<std::endl;
//}
//
//compare function is more flexible
//s1.compare(3,2,s2);//start the comparision at position of 3 and compare 2 characters
//string ss= s1+s2;// concatinate two strings and assigned to ss



//Non-Member functions
//std::cout<<s1<<std::endl;
//std::cin>> s1; //read a line 
//getline(cin,s1) is same as std::cin>>s1 
//getline also allows you to specify your own delimiter
//getline(cin, s1,';')//delimeter is ';'
//to_string() converts numbers to a string
//
//
//
//convert number into a string


//to_string(8);
//s1=to_string(2.3e7) // s1= 230000000.0000
//convert hexadecimal numbers to strings
//s1=to_string(0xa4);//s1:164
//s1=to_string(034);//s1:23
//
//
//
//
//
//
// Convert string into a number
// s1="190"
// int i=stoi(s1); // i:190
// s1="190 monkeys";
// size_t pos;
// i=stoi(s1, &pos);
// //i=190
// pos  is the index of the character 






// s1= "a monkey";
// i=stoi(s1, &pos); //exception of invalid_argument
// i=stoi(s1,&pos,16);//extract hexadecimal number from s1 i=10
// stoi converts strings to integer
// stol, stod, stof etc converts string to long,double, float
// stringstream
// lexical_cast()
//

//<string>
////String and Algorithms
//s1="Variety is the spice of life.";
//int num=count(s1.begin().s1.end(),'e') returns 4
//num=count_if(s1.begin(),s1.end(), [](char c){return (c<='e' && c>='a');}); //reuturns 6
//s1="goodness is better than beauty."
//string::iterator itr=search_n(s1.begin(),s1.begin()+20,2,'s')
//search 2 consecutive's' in first twenty characters of string s1)
//itr is pointing to first s
//s1.erase(itr, itr+5);
//this will remove the five characters starting from the position fo itr
//s1.insert(itr,3,'x');
//insert 3 x at the position of iter
//s1.replace(itr, itr+3,3,'y'); replace 3 characters starting from iter and 
//is_permutation(s1.begin(),s1.end(),s2.begin());
//tell if s1 is a permutation of s2
//replace(s1.begin(),s1.end(),'e','  ');
//replaces all the 
//member function replace is replacing substring
//algorithm replacing is replacing characters
//transfrom(s1.begin(),s1.end(),s2.begin(),[](char c){ if(c<'n'){return 'a';} return 'z'});
//s2 will contains azzazzaaaazzazzazaazaaazzzz;
//s1="abcdefg"
//rotate(s1.begin(),s1.begin()+3,s1.end());
//s1 becomes defgabc
//
//
//
//
//u16string s1;// string char16_t
//u32string s10 // string char32_t
//wstring s0 // string wchar_t (wide character)
//the above functions can also be applied to above strings
//
