/*
**      General Purpose DSP Library
**
**      Original Copyright (C) 2017 - 2018 HORIGUCHI Junshi.
**                                          http://iridium.jp/
**                                          zap00365@nifty.com
**      Portions Copyright (C) <year> <author>
**                                          <website>
**                                          <e-mail>
**      Version     POSIX / C++11
**      Website     http://iridium.jp/
**      E-mail      zap00365@nifty.com
**
**      This source code is for Xcode.
**      Xcode 9.2 (Apple LLVM 9.0.0)
**
**      GPDSPFlexInputtableNode.hpp
**
**      ------------------------------------------------------------------------
**
**      The MIT License (MIT)
**
**      Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
**      associated documentation files (the "Software"), to deal in the Software without restriction,
**      including without limitation the rights to use, copy, modify, merge, publish, distribute,
**      sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
**      furnished to do so, subject to the following conditions:
**      The above copyright notice and this permission notice shall be included in all copies or
**      substantial portions of the Software.
**      THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
**      BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
**      IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
**      WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
**      OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
**
**      以下に定める条件に従い、本ソフトウェアおよび関連文書のファイル（以下「ソフトウェア」）の複製を
**      取得するすべての人に対し、ソフトウェアを無制限に扱うことを無償で許可します。
**      これには、ソフトウェアの複製を使用、複写、変更、結合、掲載、頒布、サブライセンス、および、または販売する権利、
**      およびソフトウェアを提供する相手に同じことを許可する権利も無制限に含まれます。
**      上記の著作権表示および本許諾表示を、ソフトウェアのすべての複製または重要な部分に記載するものとします。
**      ソフトウェアは「現状のまま」で、明示であるか暗黙であるかを問わず、何らの保証もなく提供されます。
**      ここでいう保証とは、商品性、特定の目的への適合性、および権利非侵害についての保証も含みますが、それに限定されるものではありません。
**      作者または著作権者は、契約行為、不法行為、またはそれ以外であろうと、ソフトウェアに起因または関連し、
**      あるいはソフトウェアの使用またはその他の扱いによって生じる一切の請求、損害、その他の義務について何らの責任も負わないものとします。
*/

#ifndef __GPDSPFLEXINPUTTABLENODE_HPP
#define __GPDSPFLEXINPUTTABLENODE_HPP

/*!
    @file
    @brief ir::GPDSPFlexInputtableNode クラス
 */

#include "GPDSPInputtableNode.hpp"

namespace ir {

//! 可変個数の入力ターミナルを持つノードを表す抽象クラス
/*!
    GPDSPFlexInputtableNode クラスは, 可変個数の入力ターミナルを持つノードを表す抽象クラスです.
 
    可変個数の入力ターミナルを持つ各種ノードを表す具象クラスは, GPDSPFlexInputtableNode クラスを継承して実装します.
 */
class GPDSPFlexInputtableNode : public GPDSPInputtableNode {
    public:
        //! 入力ターミナルの個数と名前を設定します.
        /*!
            @param[in] count 設定する個数
            @param[in] what 設定する名前
            @retval #GPDSPERROR_OK 正常
            @retval #GPDSPERROR_NO_MEMORY メモリが不足している
         */
                GPDSPError                  setCountI                   (int count, std::string const& what) noexcept;
        //! 引数に指定された名前を持つ入力ターミナルを追加します.
        /*!
            @param[in] what 追加する名前
            @retval #GPDSPERROR_OK 正常
            @retval #GPDSPERROR_NO_MEMORY メモリが不足している
         */
                GPDSPError                  appendI                     (std::string const& what) noexcept;
        //! 引数に指定された名前を持つ入力ターミナルを挿入します.
        /*!
            @param[in] index 挿入する位置
            @param[in] what 挿入する名前
            @retval #GPDSPERROR_OK 正常
            @retval #GPDSPERROR_NO_MEMORY メモリが不足している
            @retval #GPDSPERROR_INVALID_RANGE 範囲外のパラメータ
         */
                GPDSPError                  insertI                     (int index, std::string const& what) noexcept;
        //! 入力ターミナルを削除します.
        /*!
            @param[in] index ターミナル番号
            @retval #GPDSPERROR_OK 正常
            @retval #GPDSPERROR_INVALID_RANGE 範囲外のパラメータ
         */
                GPDSPError                  removeI                     (int index) noexcept;
        //! すべての入力ターミナルを削除します.
                void                        clearI                      (void) noexcept;
    protected:
        //! コンストラクタです.
        /*!
            何もしません.
         */
        explicit                            GPDSPFlexInputtableNode     (void) noexcept;
        //! デストラクタです.
        /*!
            何もしません.
         */
        virtual                             ~GPDSPFlexInputtableNode    (void) noexcept = 0;
    private:
                                            GPDSPFlexInputtableNode     (GPDSPFlexInputtableNode const&);
                GPDSPFlexInputtableNode&    operator=                   (GPDSPFlexInputtableNode const&);
};

inline GPDSPError GPDSPFlexInputtableNode::setCountI(int count, std::string const& what) noexcept
{
    return GPDSPInputtableNode::setCountI(count, what);
}

inline GPDSPError GPDSPFlexInputtableNode::appendI(std::string const& what) noexcept
{
    return GPDSPInputtableNode::appendI(what);
}

inline GPDSPError GPDSPFlexInputtableNode::insertI(int index, std::string const& what) noexcept
{
    return GPDSPInputtableNode::insertI(index, what);
}

inline GPDSPError GPDSPFlexInputtableNode::removeI(int index) noexcept
{
    return GPDSPInputtableNode::removeI(index);
}

inline void GPDSPFlexInputtableNode::clearI(void) noexcept
{
    GPDSPInputtableNode::clearI();
    return;
}

}// end of namespace

#endif
