#coding: utf-8
import os
import binascii

def fromHDR(filename):
    with open(filename) as f:
        lines = f.readlines()
        res_list = []
        for line in lines:
            r_line = []
            line = line.split('\n')[0]
            line = line.split(' ')
            ret = []
            for substr in line:
                r_sub = []
                if '\t' in substr:
                    substr = substr.split('\t')
                    for ssub in substr:
                        if ssub != '':
                            r_sub.append(ssub)
                    substr = r_sub
                if substr != '':
                    if type(substr) is type(list()):
                        ret += substr
                    else:
                        ret.append(substr)
            if len(ret)==3 and ret[0] == '#define':
                res_list.append(ret[1:])
        for n in range(len(res_list)):
            v = 0
            str_num = res_list[n][-1]
            for idx in range(1, len(str_num)-1):
                v += int(str_num[len(str_num)-idx]) * 2**(idx-1)
            res_list[n][-1] = str(v)
            print res_list[n]
        with open('../bin/Resource.ini', 'wb') as scp:
            for res in res_list:
                scp.write('\t'+'\t'.join(res)+'\n')
        


if __name__ == '__main__':
    fromHDR('../src/Resource.h')