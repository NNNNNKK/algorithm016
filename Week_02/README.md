# 学习笔记
## 一、哈希表、映射、集合
 - hash定义
       哈希表（Hash table），也叫散列表，是根据关键码值（Key value）而直接进行访问的数据结构。它通过把关键码值映射到表中一个位置来访问记录，以加快查找的速度。这个映射函数叫作散列函数（Hash Function），存放记录的数组叫作哈希表（或散列表）。
 - 工程实践
 电话号码簿、用户信息表、缓存（LRU Cache）和键值对存储（Redis）等。
 
 - hash 函数
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/20200919202124572.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MjIwMjY3NA==,size_16,color_FFFFFF,t_70#pic_center)
 - hash 碰撞
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/20200919202223916.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MjIwMjY3NA==,size_16,color_FFFFFF,t_70#pic_center)
 - set、map
 map是key-value对，key不重复；set：不重复元素的集合.
 
##    二、树、二叉树、二叉搜索树
 
 - 树和图
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/20200919202748854.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MjIwMjY3NA==,size_16,color_FFFFFF,t_70#pic_center)
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/2020091920290695.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MjIwMjY3NA==,size_16,color_FFFFFF,t_70#pic_center)
 - 链表是特殊的树，树是特殊的图
 - 二叉树的遍历：
 1.前序（Pre-order）：根-左-右
 2.中序（In-order）：左-根-右
 3.后序（Post-order）：左-右-根
 常用的遍历算法：1.递归；2.迭代+栈。
 
 - 二叉搜索树
 二叉搜索树，也称二叉排序树、有序二叉树（Ordered Binary Tree）、排序二叉树（Sorted Binary Tree），是指一棵空树或者具有下列性质的二叉树：
1.左子树上所有结点的值均小于它的根结点的值；
2.右子树上所有结点的值均大于它的根结点的值；
3.以此类推：左、右子树也分别为二叉查找树。
**中序遍历：升序排列**

##  三、堆和二叉堆

 - 堆的顶部为最大或者最小值，最大的叫大顶堆，最小的叫小顶堆。查找最值得时间复杂度都为O(1)。
 - 二叉堆通过完全二叉树来实现，实际用数组来做的。索引为i的左孩子的索引是2i+1;索引为i的右孩子的索引是2i+2;索引为的父结点的索引是floor（（i-1）/2）;
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/20200919204131907.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MjIwMjY3NA==,size_16,color_FFFFFF,t_70#pic_center)


 
