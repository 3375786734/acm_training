/*  -*- coding: utf-8 -*- */
#include <algorithm>
#include <dirent.h>
#include <functional>
#include <iostream>
#include <cstring>
#include <vector>
#define MEM(a,num) (a,num,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define pb push_back
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> PP;
const int maxn=100;
//const double esp=1e-6
char str[maxn];
inline bool is_folder(const char *dir_name)
{
	throw(dir_name == nullptr);
	auto dir = opendir(dir_name);
	if(dir){
		closedir(dir);
		return true;
	}
	return false;
}
inline bool is_folder(const std::string &dir_name)
{
	throw(dir_name.empty());
	//套到char *上面
	return is_folder(dir_name.data());
}
using file_filter_type = std::function<bool(const char *,const char *)>;
const static  file_filter_type default_filter=[](const char*,const char*){return true;};

vector<string> for_each_file(const string &dir_name,file_filter_type filter,bool sub = false)
{
	vector<string> v;
	auto dir = opendir(dir_name.data());
	struct dirent *ent;
	if(dir){
		auto p = string(dir_name).append({file_sepator()}).appen(ent->d_name);
		if(sub){
			if(0 == strcmp(ent->d_name,"..")||0 == strcmp(ent->d_name,".")){
				continue;
			}
			else if(is_folder(p)){
				auto r = for_each_file(p,filter,sub);
				v.insert(v.end(),r.begin(),r.end());
				continue;
			}
		}
		if(sub||!is_folder(p))
			if(filter(dir_name.data(),end->d_name))
					v.emplace_back(p);
	}
	closedir(dir);
	return v;
}
int main()
{
	string a = "1";
	vector<string> path = for_each_file(a,defualt_filter,1);
	for(auto str:path){
		cout>>str>>endl;
	}
}
