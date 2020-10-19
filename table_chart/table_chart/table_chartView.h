
// table_chartView.h: CtablechartView 클래스의 인터페이스
//

#pragma once


class CtablechartView : public CView
{
protected: // serialization에서만 만들어집니다.
	CtablechartView() noexcept;
	DECLARE_DYNCREATE(CtablechartView)

// 특성입니다.
public:
	CtablechartDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CtablechartView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	char sta;
	CPoint m_Lefttop;
	CPoint m_Rightbottom;
	CPoint m_startrow;
	CPoint m_endrow;
	CPoint m_startcolumn;
	CPoint m_endcolumn;
	CPoint first_chartLT;
	CPoint first_chartRB;
	CPoint second_chartLT;
	CPoint second_chartRB;
	CPoint third_chartLT;
	CPoint third_chartRB;
};

#ifndef _DEBUG  // table_chartView.cpp의 디버그 버전
inline CtablechartDoc* CtablechartView::GetDocument() const
   { return reinterpret_cast<CtablechartDoc*>(m_pDocument); }
#endif

