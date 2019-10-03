import numpy as np
import pandas as pd
from tqdm import tqdm
import csv
import os
fileNameStr = 'D:\SeedCup_pre_train.csv' #文件所在
DataDF = pd.read_csv(fileNameStr,encoding = "utf-8",dtype = str) 

#print(DataDF.info())#宏观的角度 
#print(DataDF.dtypes)#查看数据类型
#print(DataDF.shape)#数据维度
#uid 前面有一个空格 部分列名需要修改
colNameDict = {' uid':'uid'}     
DataDF.rename(columns = colNameDict,inplace=True)

#数据类型调整
''' 测试集中能用的数据  (100000, 14)
0 uid	买家id int
1 plat_form	 交易平台 int
2 biz_type	业务来源 int
3 create_time	订单创建时间 string
4 payed_time	订单支付时间  string
5 product_id	商品id int
6 cate1_id	商品类目1级 int
7 cate2_id	商品类目2级 int
8 cate3_id	商品类目3级 int
9 preselling_shipped_time  预售时间 存在噪声 string
10 seller_uid	商家id int 
11 company_name	商家公司id int
12 rvcr_prov_name	收货省份id int
13 rvcr_city_name   收货城市id int

训练集中的数据
14 lgst_company    物流公司id            
warehouse_id       仓库id
shipped_prov_id    发货省份id  
shipped_city_id    发货城市id
shipped_time       发货时间
got_time           揽件时间 
dlved_time         走件时间 
signed_time        签收时间
'''

DataDF['uid']=DataDF['uid'].astype('int')
DataDF['plat_form']=DataDF['plat_form'].astype('int')
DataDF['biz_type']=DataDF['biz_type'].astype('int')
DataDF['product_id']=DataDF['product_id'].astype('int')
DataDF['cate1_id']=DataDF['cate1_id'].astype('int')
DataDF['cate2_id']=DataDF['cate2_id'].astype('int')
DataDF['cate3_id']=DataDF['cate3_id'].astype('int')
DataDF['seller_uid']=DataDF['seller_uid'].astype('int')
DataDF['company_name']=DataDF['company_name'].astype('int')
DataDF['rvcr_prov_name']=DataDF['rvcr_prov_name'].astype('int')
DataDF['rvcr_city_name']=DataDF['rvcr_city_name'].astype('int')
DataDF['lgst_company']=DataDF['lgst_company'].astype('int')
DataDF['warehouse_id ']=DataDF['warehouse_id'].astype('int')
DataDF['shipped_prov_id']=DataDF['shipped_prov_id'].astype('int')
DataDF['shipped_city_id']=DataDF['shipped_city_id'].astype('int')



#调整为日期格式
#DataDF.loc[:,'InvoiceDate']=pd.to_datetime(DataDF.loc[:,'InvoiceDate'],
# format='%d/%m/%Y', 
#errors='coerce')  
#不需清洗
DataDF['create_time']=pd.to_datetime(DataDF['create_time'],
format='%m/%d/%Y %H:%M:%S',errors='coerce')
#不需清洗

DataDF['payed_time']=pd.to_datetime(DataDF['payed_time'],
format='%m/%d/%Y %H:%M:%S',errors='coerce')
#发货时间
'''
count                  373650 
unique                 101496
top       2019-02-03 10:39:16
freq                       86
first     2019-01-03 01:09:18
last      2019-12-03 18:09:56
'''
DataDF['shipped_time']=pd.to_datetime(DataDF['shipped_time'],
format='%m/%d/%Y %H:%M:%S',errors='coerce')
#删除shipped_time异常那一行
querySer=DataDF.loc[:,'shipped_time']>='2019-01-03 01:09:18'
DataDF=DataDF.loc[querySer,:]
#删除got_time异常
DataDF['got_time']=pd.to_datetime(DataDF['got_time'],
format='%m/%d/%Y %H:%M:%S',errors='coerce')
querySer=DataDF.loc[:,'got_time']>='2018-09-04 11:33:07'
DataDF=DataDF.loc[querySer,:]

#删除dlved异常
DataDF['dlved_time']=pd.to_datetime(DataDF['dlved_time'],
format='%m/%d/%Y %H:%M:%S',errors='coerce')
querySer=DataDF.loc[:,'dlved_time']>='2018-04-12 22:56:28'
DataDF=DataDF.loc[querySer,:]

#签收时间
DataDF['signed_time']=pd.to_datetime(DataDF['signed_time'],
format='%m/%d/%Y %H:%M:%S',errors='coerce')
querySer=DataDF.loc[:,'signed_time']>='2018-09-04 13:58:55'
DataDF=DataDF.loc[querySer,:]

'''
###清洗 preselling_shipped_time 

'''

#预售时间 大量噪声数据
DataDF['preselling_shipped_time']=pd.to_datetime(DataDF['preselling_shipped_time'],
format='%m/%d/%Y %H:%M:%S',errors='coerce')
#先全部删除垃圾数据
querySer=DataDF.loc[:,'preselling_shipped_time']>='1970-01-01 08:00:00'
DataDF=DataDF.loc[querySer,:]
querySer=DataDF.loc[:,'preselling_shipped_time']!='1970-01-01 08:00:00'
DataDF=DataDF.loc[querySer,:]
DataDF['preselling_shipped_time']=pd.to_datetime(DataDF['preselling_shipped_time'],
format='%m/%d/%Y %H:%M:%S',errors='coerce')


#逻辑判断 DataDF.loc[:,'uid']>0 
#describe()  方法 查看数据情况 


#文件保存
DataDF.to_csv('cleanfile.csv', encoding='utf-8')


print(DataDF.info())











