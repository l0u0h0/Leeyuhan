
// table_chartView.cpp: CtablechartView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "table_chart.h"
#endif

#include "table_chartDoc.h"
#include "table_chartView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CtablechartView

IMPLEMENT_DYNCREATE(CtablechartView, CView)

BEGIN_MESSAGE_MAP(CtablechartView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CtablechartView 생성/소멸

CtablechartView::CtablechartView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CtablechartView::~CtablechartView()
{
}

BOOL CtablechartView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CtablechartView 그리기

void CtablechartView::OnDraw(CDC* pDC)
{
	CtablechartDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	pDC->TextOutW(200, 200, L"just type 's' to get started");
	switch (sta) {
	case 's':
		pDC->TextOutW(200, 180, L"Hello, drawing table and chart");
		pDC->TextOutW(200, 200, L"just type 't' to get started drawing table");
		pDC->TextOutW(200, 220, L"just type 'c' to get started drawing chart");
		break;
	case 't':
		pDC->Rectangle(m_Lefttop.x, m_Lefttop.y,
			m_Rightbottom.x, m_Rightbottom.y);
		if (t_row <= 100) {
			for (int i = 0; i < 2; i++) {
				m_startrow.x = m_Lefttop.x;
				m_startrow.y = (m_Rightbottom.y - m_Lefttop.y) * 0.5 * i + m_Lefttop.y;
				m_endrow.x = m_Rightbottom.x;
				m_endrow.y = m_startrow.y;
				pDC->MoveTo(m_startrow);
				pDC->LineTo(m_endrow);
			}
		}
		else if (t_row > 100 && t_row <= 150) {
			for (int i = 0; i < 3; i++) {
				m_startrow.x = m_Lefttop.x;
				m_startrow.y = (m_Rightbottom.y - m_Lefttop.y) * 0.33 * i + m_Lefttop.y;
				m_endrow.x = m_Rightbottom.x;
				m_endrow.y = m_startrow.y;
				pDC->MoveTo(m_startrow);
				pDC->LineTo(m_endrow);
			}
		}
		else if (t_row > 150 && t_row <= 250) {
			for (int i = 0; i < 4; i++) {
				m_startrow.x = m_Lefttop.x;
				m_startrow.y = (m_Rightbottom.y - m_Lefttop.y) * 0.25 * i + m_Lefttop.y;
				m_endrow.x = m_Rightbottom.x;
				m_endrow.y = m_startrow.y;
				pDC->MoveTo(m_startrow);
				pDC->LineTo(m_endrow);
			}
		}
		else if (t_row > 250 && t_row <= 350) {
			for (int i = 0; i < 5; i++) {
				m_startrow.x = m_Lefttop.x;
				m_startrow.y = (m_Rightbottom.y - m_Lefttop.y) * 0.2 * i + m_Lefttop.y;
				m_endrow.x = m_Rightbottom.x;
				m_endrow.y = m_startrow.y;
				pDC->MoveTo(m_startrow);
				pDC->LineTo(m_endrow);
			}
		}
		else if (t_row > 350) {
			for (int i = 0; i < 6; i++) {
				m_startrow.x = m_Lefttop.x;
				m_startrow.y = (m_Rightbottom.y - m_Lefttop.y) * 0.167 * i + m_Lefttop.y;
				m_endrow.x = m_Rightbottom.x;
				m_endrow.y = m_startrow.y;
				pDC->MoveTo(m_startrow);
				pDC->LineTo(m_endrow);
			}
		}
		if (t_column <= 230) {
			for (int k = 0; k < 2; k++) {
				m_startcolumn.x = (m_Rightbottom.x - m_Lefttop.x) * 0.5 * k + m_Lefttop.x;
				m_startcolumn.y = m_Lefttop.y;
				m_endcolumn.x = m_startcolumn.x;
				m_endcolumn.y = m_Rightbottom.y;
				pDC->MoveTo(m_startcolumn);
				pDC->LineTo(m_endcolumn);
			}
		}
		else if (t_column > 230 && t_column <= 400) {
			for (int k = 0; k < 3; k++) {
				m_startcolumn.x = (m_Rightbottom.x - m_Lefttop.x) * 0.33 * k + m_Lefttop.x;
				m_startcolumn.y = m_Lefttop.y;
				m_endcolumn.x = m_startcolumn.x;
				m_endcolumn.y = m_Rightbottom.y;
				pDC->MoveTo(m_startcolumn);
				pDC->LineTo(m_endcolumn);
			}
		}
		else if (t_column > 400 && t_column <= 600) {
			for (int k = 0; k < 4; k++) {
				m_startcolumn.x = (m_Rightbottom.x - m_Lefttop.x) * 0.25 * k + m_Lefttop.x;
				m_startcolumn.y = m_Lefttop.y;
				m_endcolumn.x = m_startcolumn.x;
				m_endcolumn.y = m_Rightbottom.y;
				pDC->MoveTo(m_startcolumn);
				pDC->LineTo(m_endcolumn);
			}
		}
		else if (t_column > 600 && t_column <= 800) {
			for (int k = 0; k < 5; k++) {
				m_startcolumn.x = (m_Rightbottom.x - m_Lefttop.x) * 0.2 * k + m_Lefttop.x;
				m_startcolumn.y = m_Lefttop.y;
				m_endcolumn.x = m_startcolumn.x;
				m_endcolumn.y = m_Rightbottom.y;
				pDC->MoveTo(m_startcolumn);
				pDC->LineTo(m_endcolumn);
			}
		}
		else if (t_column > 800) {
			for (int k = 0; k < 6; k++) {
				m_startcolumn.x = (m_Rightbottom.x - m_Lefttop.x) * 0.167 * k + m_Lefttop.x;
				m_startcolumn.y = m_Lefttop.y;
				m_endcolumn.x = m_startcolumn.x;
				m_endcolumn.y = m_Rightbottom.y;
				pDC->MoveTo(m_startcolumn);
				pDC->LineTo(m_endcolumn);
			}
		}
		break;
	case 'c':
		pDC->Rectangle(m_Lefttop.x, m_Lefttop.y,
			m_Rightbottom.x, m_Rightbottom.y);
		first_chartLT.x = (m_Rightbottom.x - m_Lefttop.x) * (0.14) + m_Lefttop.x;
		first_chartLT.y = (m_Rightbottom.y - m_Lefttop.y) * 0.5 + m_Lefttop.y;
		first_chartRB.x = (m_Rightbottom.x - m_Lefttop.x) * (0.14) + first_chartLT.x;
		first_chartRB.y = m_Rightbottom.y;
		pDC->Rectangle(first_chartLT.x, first_chartLT.y, first_chartRB.x, first_chartRB.y);
		second_chartLT.x = (m_Rightbottom.x - m_Lefttop.x) * 0.42 + m_Lefttop.x;
		second_chartLT.y = (m_Rightbottom.y - m_Lefttop.y) * 0.75 + m_Lefttop.y;
		second_chartRB.x = (m_Rightbottom.x - m_Lefttop.x) * 0.14 + second_chartLT.x;
		second_chartRB.y = m_Rightbottom.y;
		pDC->Rectangle(second_chartLT.x, second_chartLT.y, second_chartRB.x, second_chartRB.y);
		third_chartLT.x = (m_Rightbottom.x - m_Lefttop.x) * 0.7 + m_Lefttop.x;
		third_chartLT.y = (m_Rightbottom.y - m_Lefttop.y) * 0.25 + m_Lefttop.y;
		third_chartRB.x = (m_Rightbottom.x - m_Lefttop.x) * 0.14 + third_chartLT.x;
		third_chartRB.y = m_Rightbottom.y;
		pDC->Rectangle(third_chartLT.x, third_chartLT.y, third_chartRB.x, third_chartRB.y);
		break;
	default:
		break;
	}
}


// CtablechartView 인쇄

BOOL CtablechartView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CtablechartView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CtablechartView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CtablechartView 진단

#ifdef _DEBUG
void CtablechartView::AssertValid() const
{
	CView::AssertValid();
}

void CtablechartView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CtablechartDoc* CtablechartView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CtablechartDoc)));
	return (CtablechartDoc*)m_pDocument;
}
#endif //_DEBUG


// CtablechartView 메시지 처리기


void CtablechartView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	switch (nChar)
	{
	case 's':
		sta = 's';
		Invalidate();
		break;
	case 't':
		sta = 't';
		Invalidate();
		break;
	case 'c':
		sta = 'c';
		Invalidate();
		break;
	default:
		break;
	}
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CtablechartView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_Lefttop = point;

	CView::OnLButtonDown(nFlags, point);
}


void CtablechartView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_Rightbottom = point;
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}


void CtablechartView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nFlags & MK_LBUTTON) {
		m_Rightbottom = point;
		t_row = Length_row(m_Lefttop, m_Rightbottom);
		t_column = Length_column(m_Lefttop, m_Rightbottom);
		Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}

int CtablechartView::Length_row(CPoint m_Lefttop, CPoint m_Rightbottom)
{
	// TODO: 여기에 구현 코드 추가.
	return (m_Rightbottom.y - m_Lefttop.y);
}


int CtablechartView::Length_column(CPoint m_Lefttop, CPoint m_Rightbottom)
{
	// TODO: 여기에 구현 코드 추가.
	return (m_Rightbottom.x - m_Lefttop.x);
}
