/*
idea:求解方法是,按y从小到大的区间建一颗线段树,节点中存的是x的大小,也就是横线的大小,同理按x从小到达建一个线段树存的是y坐标大小.然后从后往前更新,可以发现,当前的被档只有可能是因为后面有x比其大,但$ y' $比他小的,会将当前海浪的$ y' $减去,对与另一个坐标同理
实现比较简单,不在这里写出来了.
*/
