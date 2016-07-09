
' ========================================================================================
' Save all options to the gConfig class
' ========================================================================================
Sub SaveEditorOptions()    
   
   Dim HWnd As HWnd 
   Dim wText As WString * MAX_PATH  
    
   ' GENERAL OPTIONS   
   HWnd = HWND_FRMOPTIONSGENERAL
   gConfig.MultipleInstances    = Button_GetCheck( GetDlgItem(HWnd, IDC_FRMOPTIONSGENERAL_CHKMULTIPLEINSTANCES) )
   gConfig.CompileAutosave      = Button_GetCheck( GetDlgItem(HWnd, IDC_FRMOPTIONSGENERAL_CHKCOMPILEAUTOSAVE) )
   gConfig.CloseFuncList        = Button_GetCheck( GetDlgItem(HWnd, IDC_FRMOPTIONSGENERAL_CHKCLOSEFUNCLIST) )
   gConfig.CloseProjMgr         = Button_GetCheck( GetDlgItem(HWnd, IDC_FRMOPTIONSGENERAL_CHKCLOSEPROJMGR) )
   gConfig.HideCompile          = Button_GetCheck( GetDlgItem(HWnd, IDC_FRMOPTIONSGENERAL_CHKHIDECOMPILE) )

   ' EDITOR OPTIONS   
   HWnd = HWND_FRMOPTIONSEDITOR
   gConfig.SyntaxHighlighting   = Button_GetCheck( GetDlgItem(HWnd, IDC_FRMOPTIONSEDITOR_CHKSYNTAXHIGHLIGHTING) )
   gConfig.Codetips             = Button_GetCheck( GetDlgItem(HWnd, IDC_FRMOPTIONSEDITOR_CHKCODETIPS) )
   gConfig.LeftMargin           = Button_GetCheck( GetDlgItem(HWnd, IDC_FRMOPTIONSEDITOR_CHKSHOWLEFTMARGIN) )
   gConfig.FoldMargin           = Button_GetCheck( GetDlgItem(HWnd, IDC_FRMOPTIONSEDITOR_CHKSHOWFOLDMARGIN) )
   gConfig.ConfineCaret         = Button_GetCheck( GetDlgItem(HWnd, IDC_FRMOPTIONSEDITOR_CHKCONFINECARET) )
   gConfig.LineNumbering        = Button_GetCheck( GetDlgItem(HWnd, IDC_FRMOPTIONSEDITOR_CHKLINENUMBERING) )
   gConfig.HighlightCurrentLine = Button_GetCheck( GetDlgItem(HWnd, IDC_FRMOPTIONSEDITOR_CHKCURRENTLINE) )
   gConfig.TabIndentSpaces      = Button_GetCheck( GetDlgItem(HWnd, IDC_FRMOPTIONSEDITOR_CHKTABTOSPACES) )
   gConfig.IndentGuides         = Button_GetCheck( GetDlgItem(HWnd, IDC_FRMOPTIONSEDITOR_CHKINDENTGUIDES ) )
   gConfig.AutoIndentation      = Button_GetCheck( GetDlgItem(HWnd, IDC_FRMOPTIONSEDITOR_CHKAUTOINDENTATION) )

   FF_Control_GetTextW( GetDlgItem(HWnd, IDC_FRMOPTIONSEDITOR_TXTTABSIZE), @gConfig.TabSize, Sizeof(gConfig.TabSize) )
   gConfig.KeywordCase = ComboBox_GetCurSel( GetDlgItem( HWnd, IDC_FRMOPTIONSEDITOR_COMBOCASE))
   
   ' If the localization has changed then display a message indicating that the changes
   ' will not be seen until the application is restarted.
   HWnd = HWND_FRMOPTIONSLOCAL
   FF_Control_GetTextW( GetDlgItem(HWnd, IDC_FRMOPTIONSLOCAL_LBLLOCALIZATION), @wText, Sizeof(wText) )
   If Ucase(wText) <> Ucase(gConfig.LocalizationFile) Then
      MessageBoxW( HWND_FRMMAIN, L(108,"Localization changes will be applied the next time the application is run."), _
                  L(109,"Warning"), MB_OK Or MB_ICONINFORMATION Or MB_DEFBUTTON1 Or MB_APPLMODAL )
   End If
   gConfig.LocalizationFile = wText
   
   
   ' COLOR/FONT OPTIONS
   HWnd = HWND_FRMOPTIONSCOLORS
   gConfig.clrBookmarksFG       = gTempColors(0).nFg 
   gConfig.clrBookmarksBG       = gTempColors(0).nBg
   gConfig.clrCaretFG           = gTempColors(1).nFg
   gConfig.clrCaretBG           = gTempColors(1).nBg
   gConfig.clrCommentsFG        = gTempColors(2).nFg
   gConfig.clrCommentsBG        = gTempColors(2).nBg
   gConfig.clrHighlightedFG     = gTempColors(3).nFg
   gConfig.clrHighlightedBG     = gTempColors(3).nBg
   gConfig.clrKeywordFG         = gTempColors(4).nFg
   gConfig.clrKeywordBG         = gTempColors(4).nBg
   gConfig.clrFoldMarginFG      = gTempColors(5).nFg
   gConfig.clrFoldMarginBG      = gTempColors(5).nBg
   gConfig.clrFoldSymbolFG      = gTempColors(6).nFg
   gConfig.clrFoldSymbolBG      = gTempColors(6).nBg
   gConfig.clrIndentGuidesFG    = gTempColors(7).nFg
   gConfig.clrIndentGuidesBG    = gTempColors(7).nBg
   gConfig.clrLineNumbersFG     = gTempColors(8).nFg
   gConfig.clrLineNumbersBG     = gTempColors(8).nBg
   gConfig.clrOperatorsFG       = gTempColors(9).nFg
   gConfig.clrOperatorsBG       = gTempColors(9).nBg
   gConfig.clrPreprocessorFG    = gTempColors(10).nFg
   gConfig.clrPreprocessorBG    = gTempColors(10).nBg
   gConfig.clrSelectionFG       = gTempColors(11).nFg
   gConfig.clrSelectionBG       = gTempColors(11).nBg
   gConfig.clrStringsFG         = gTempColors(12).nFg
   gConfig.clrStringsBG         = gTempColors(12).nBg
   gConfig.clrTextFG            = gTempColors(13).nFg
   gConfig.clrTextBG            = gTempColors(13).nBg
   gConfig.clrWinApiBG          = gTempColors(14).nFg
   gConfig.clrWinApiBG          = gTempColors(14).nBg
   gConfig.clrWindowFG          = gTempColors(15).nFg
   gConfig.clrWindowBG          = gTempColors(15).nBg

   Dim idx As Long 
   idx = ComboBox_GetCurSel( GetDlgItem(HWnd, IDC_FRMOPTIONSCOLORS_COMBOFONTNAME) )
   FF_ComboBox_GetTextW( GetDlgItem(HWnd, IDC_FRMOPTIONSCOLORS_COMBOFONTNAME), idx, @gConfig.EditorFontname, Sizeof(gConfig.EditorFontname) )
   idx = ComboBox_GetCurSel( GetDlgItem(HWnd, IDC_FRMOPTIONSCOLORS_COMBOFONTSIZE) )
   FF_ComboBox_GetTextW( GetDlgItem(HWnd, IDC_FRMOPTIONSCOLORS_COMBOFONTSIZE), idx, @gConfig.EditorFontSize, Sizeof(gConfig.EditorFontSize) )
   idx = ComboBox_GetCurSel( GetDlgItem(HWnd, IDC_FRMOPTIONSCOLORS_COMBOFONTCHARSET) )
   FF_ComboBox_GetTextW( GetDlgItem(HWnd, IDC_FRMOPTIONSCOLORS_COMBOFONTCHARSET), idx, @gConfig.EditorFontCharSet, Sizeof(gConfig.EditorFontCharSet) )
   
   ' COMPILER OPTIONS
   HWnd = HWND_FRMOPTIONSCOMPILER
   FF_Control_GetTextW( GetDlgItem(HWnd, IDC_FRMOPTIONSCOMPILER_TXTFBWIN32), @gConfig.FBWINCompiler32, Sizeof(gConfig.FBWINCompiler32) ) 
   FF_Control_GetTextW( GetDlgItem(HWnd, IDC_FRMOPTIONSCOMPILER_TXTFBWIN64), @gConfig.FBWINCompiler64, Sizeof(gConfig.FBWINCompiler64) )
   FF_Control_GetTextW( GetDlgItem(HWnd, IDC_FRMOPTIONSCOMPILER_TXTFBSWITCHES), @gConfig.CompilerSwitches, Sizeof(gConfig.CompilerSwitches) )
   FF_Control_GetTextW( GetDlgItem(HWnd, IDC_FRMOPTIONSCOMPILER_TXTFBHELPFILE), @gConfig.CompilerHelpfile, Sizeof(gConfig.CompilerHelpfile) )
   FF_Control_GetTextW( GetDlgItem(HWnd, IDC_FRMOPTIONSCOMPILER_TXTWIN32HELPPATH), @gConfig.Win32APIHelpfile, Sizeof(gConfig.Win32APIHelpfile) )

   ' KEYWORDS
   If gConfig.bKeywordsDirty Then
      HWnd = HWND_FRMOPTIONSKEYWORDS
      Dim As HWnd hTextBox = GetDlgItem(HWnd, IDC_FRMOPTIONSKEYWORDS_TXTKEYWORDS)
      Dim As Long nLen = GetWindowTextLengthW(hTextBox) + 2  ' add space for ending nuls
      Dim pzswKeywords As WString Ptr = CAllocate(nLen*2)
      GetWindowTextW( hTextBox, pzswKeywords, nLen )
      Dim As String FBKeywords = Str(*pzswKeywords)
      gpApp->FBKeywords = Trim(FBKeywords)
      gpApp->SaveKeywords
      Deallocate(pzswKeywords)
   End If
   
   ' Output the config settings to disk file
   gConfig.SaveToFile

End Sub


' ========================================================================================
' Process WM_CREATE message for window/dialog: frmOptions
' ========================================================================================
Function frmOptions_OnCreate(ByVal HWnd As HWnd, ByVal lpCreateStructPtr As LPCREATESTRUCT) As BOOLEAN

   ' This is a modal popup window so disable the parent window
   EnableWindow GetParent(HWnd), False

   '  Message cracker macro expects a True to be returned for a successful
   '  OnCreate handler even though returning -1 from a standard WM_CREATE
   '  call would stop creating the window. This is just one of those Windows
   '  inconsistencies.
   Return True
End Function


' ========================================================================================
' Process WM_COMMAND message for window/dialog: frmOptions
' ========================================================================================
Function frmOptions_OnCommand(ByVal HWnd As HWnd, ByVal id As Long, ByVal hwndCtl As HWnd, ByVal codeNotify As UINT) As LRESULT

   Select Case id
      Case IDOK
         If codeNotify = BN_CLICKED Then
            SaveEditorOptions()
            ' Apply the newly saved options to all open Scintilla windows
            Dim As Long nCount = gpApp->GetDocumentCount 
            Dim pDoc As clsDocument Ptr
            Dim As Long i
            For i = 0 To nCount - 1
               pDoc = gpApp->GetDocumentPtr(i)
               If pDoc Then pDoc->ApplyProperties
            Next
            SendMessageW HWnd, WM_CLOSE, 0, 0
            Exit Function
         End If
      Case IDCANCEL
         If codeNotify = BN_CLICKED Then
            SendMessageW HWnd, WM_CLOSE, 0, 0
            Exit Function
         End If
   End Select

   Function = 0
End Function


' ========================================================================================
' Process WM_NOTIFY message for window/dialog: frmOptions
' ========================================================================================
Function frmOptions_OnNotify(ByVal HWnd As HWnd, ByVal id As Long, ByVal pNMHDR As NMHDR Ptr) As LRESULT

    Dim pWindow As CWindow Ptr = AfxCWindowPtr(HWnd)
    
    Select Case id
       Case IDC_FRMOPTIONS_TVWCATEGORIES
          If pNMHDR->code = TVN_SELCHANGED Then
             Dim As Long nLeft, nTop
             Dim As HWnd hForm, hLabel

             Static hCurrent As HWnd   ' hwnd of currently display child Form
             
             If hCurrent Then ShowWindow hCurrent, SW_HIDE
             
             Dim lpNMTV As NM_TREEVIEW Ptr = Cast(NM_TREEVIEW Ptr, pNMHDR)
             hLabel = GetDlgItem(HWnd, IDC_FRMOPTIONS_LBLCATEGORY)
             
             ' Display the correct Category name and Child dialog. The child identifier is held in the lParam
             Select Case FF_TreeView_GetlParam( pNMHDR->hWndFrom, lpNMTV->itemNew.hItem)
                 Case 0
                     SetWindowTextW( hLabel, WStr(" ") & L(226,"General Options")) 
                     hForm = HWND_FRMOPTIONSGENERAL
                 Case 1
                     SetWindowTextW( hLabel, WStr(" ") & L(110,"Code Editor")) 
                     hForm = HWND_FRMOPTIONSEDITOR
                 Case 2
                     SetWindowTextW( hLabel, WStr(" ") & L(111,"Colors and Fonts") )
                     hForm = HWND_FRMOPTIONSCOLORS
                 Case 3
                     SetWindowTextW( hLabel, WStr(" ") & L(112,"Compiler Setup") )
                     hForm = HWND_FRMOPTIONSCOMPILER
                 Case 4
                     SetWindowTextW( hLabel, WStr(" ") & L(129,"Localization") )
                     hForm = HWND_FRMOPTIONSLOCAL
                 Case 5
                     SetWindowTextW( hLabel, WStr(" ") & L(177,"FreeBASIC Keywords") )
                     hForm = HWND_FRMOPTIONSKEYWORDS
             End Select
             
         
             ' Move the child Form into place. The child form will be displayed under the header label.
             Dim rc As Rect
             GetWindowRect( hLabel, @rc )
             MapWindowPoints( Null, HWnd, Cast(LPPOINT, @rc), 2 )
             SetWindowPos hForm, HWND_TOP, _
                            rc.Left + pWindow->ScaleX(5), pWindow->ScaleY(50), _
                            pWindow->ScaleX(420), pWindow->ScaleY(350), _
                            SWP_SHOWWINDOW
             
             InvalidateRect HWnd, ByVal Null, True
             UpdateWindow HWnd
             
             hCurrent = hForm
          End If
   End Select

   Function = 0
End Function


' ========================================================================================
' Process WM_CTLCOLORSTATIC message for window/dialog: frmOptions
' ========================================================================================
Function frmOptions_OnCtlColorStatic(HWnd As HWnd, hdc As HDC, hWndChild As HWnd, nType As Long) As HBRUSH

   Select Case hWndChild
      Case GetDlgItem( HWnd, IDC_FRMOPTIONS_LBLCATEGORY )
         ' Set the category label to blue text 
         SetTextColor hdc, 8388608
         SetBkColor   hdc, GetSysColor( COLOR_BTNFACE )
         Function = GetSysColorBrush( COLOR_BTNFACE )
   End Select
         
End Function


' ========================================================================================
' Process WM_CLOSE message for window/dialog: frmOptions
' ========================================================================================
Function frmOptions_OnClose(HWnd As HWnd) As LRESULT
   ' Enables parent window keeping parent's zorder
   EnableWindow GetParent(HWnd), True 
   DestroyWindow HWnd
   Function = 0
End Function


' ========================================================================================
' Process WM_DESTROY message for window/dialog: frmOptions
' ========================================================================================
Function frmOptions_OnDestroy(HWnd As HWnd) As LRESULT
   Dim As HFONT hFont = AfxGetWindowFont(GetDlgItem(HWnd, IDC_FRMOPTIONS_LBLCATEGORY))
   DeleteFont(hFont)

   PostQuitMessage(0)
   Function = 0
End Function


' ========================================================================================
' frmOptions Window procedure
' ========================================================================================
Function frmOptions_WndProc( ByVal HWnd   As HWnd, _
                             ByVal uMsg   As UINT, _
                             ByVal wParam As WPARAM, _
                             ByVal lParam As LPARAM _
                             ) As LRESULT

   Select Case uMsg
      HANDLE_MSG (HWnd, WM_CREATE,   frmOptions_OnCreate)
      HANDLE_MSG (HWnd, WM_CLOSE,    frmOptions_OnClose)
      HANDLE_MSG (HWnd, WM_DESTROY,  frmOptions_OnDestroy)
      HANDLE_MSG (HWnd, WM_COMMAND,  frmOptions_OnCommand)
      HANDLE_MSG (HWnd, WM_NOTIFY,   frmOptions_OnNotify)
      HANDLE_MSG (HWnd, WM_CTLCOLORSTATIC, frmOptions_OnCtlColorStatic)
   End Select

   ' for messages that we don't deal with
   Function = DefWindowProcW(HWnd, uMsg, wParam, lParam)

End Function


' ========================================================================================
' frmOptions_Show
' ========================================================================================
Function frmOptions_Show( ByVal hWndParent As HWnd, _
                          ByVal nCmdShow   As Long = 0 _
                          ) As Long

   '  Create the main window and child controls
   Dim pWindow As CWindow Ptr = New CWindow
   pWindow->DPI = AfxCWindowPtr(hwndParent)->DPI

   pWindow->Create( hWndParent, L(113,"Environment Options"), @frmOptions_WndProc, 0, 0, 0, 0, _
        WS_POPUP Or WS_CAPTION Or WS_SYSMENU Or WS_CLIPSIBLINGS Or WS_CLIPCHILDREN, _
        WS_EX_DLGMODALFRAME Or WS_EX_CONTROLPARENT Or WS_EX_LEFT )
   pWindow->SetClientSize(625, 460)
   pWindow->Center(pWindow->hWindow, hWndParent)
      
   Dim As HWnd hLabel = _
      pWindow->AddControl("LABEL", , IDC_FRMOPTIONS_LBLCATEGORY, "Category", 216, 10, 400, 30, _
           WS_CHILD Or WS_VISIBLE Or SS_LEFT Or SS_CENTERIMAGE Or SS_NOTIFY Or SS_SUNKEN, _
           WS_EX_LEFT Or WS_EX_LTRREADING)
   Dim As HFONT hFont = pWindow->CreateFont("", 12, FW_BOLD)
   AfxSetWindowFont hLabel, hFont, True

   Dim As HWnd hWndTreeview = _
        pWindow->AddControl("TREEVIEW", , IDC_FRMOPTIONS_TVWCATEGORIES, "", 10, 10, 200, 385, _
        WS_CHILD Or WS_VISIBLE Or WS_TABSTOP Or TVS_HASBUTTONS Or TVS_HASLINES Or TVS_LINESATROOT Or TVS_SHOWSELALWAYS, _
        WS_EX_CLIENTEDGE Or WS_EX_LEFT Or WS_EX_RIGHTSCROLLBAR)
   
   pWindow->AddControl("LABEL", , IDC_FRMOPTIONS_LABEL1, "", 8, 405, 600, 3, _
        WS_CHILD Or WS_VISIBLE Or SS_LEFT Or SS_NOTIFY Or SS_SUNKEN, _
        WS_EX_LEFT Or WS_EX_LTRREADING)

   pWindow->AddControl("BUTTON", , IDOK, L(0,"&OK"), 450, 417, 74, 28, _
        WS_CHILD Or WS_VISIBLE Or WS_TABSTOP Or BS_TEXT Or BS_DEFPUSHBUTTON Or BS_NOTIFY Or BS_CENTER Or BS_VCENTER, _
        WS_EX_LEFT Or WS_EX_LTRREADING)
   
   pWindow->AddControl("BUTTON", , IDCANCEL, L(1,"&Cancel"), 535, 417, 74, 28, _
        WS_CHILD Or WS_VISIBLE Or WS_TABSTOP Or BS_TEXT Or BS_PUSHBUTTON Or BS_NOTIFY Or BS_CENTER Or BS_VCENTER, _
        WS_EX_LEFT Or WS_EX_LTRREADING)


   ' Configure the TreeView
   Dim hItem As HANDLE 
   hItem = FF_TreeView_InsertItem (hWndTreeview, TVI_ROOT, L(226,"General Options"),    0)
           FF_TreeView_InsertItem (hWndTreeview, TVI_ROOT, L(110,"Code Editor"),        1)
           FF_TreeView_InsertItem (hWndTreeview, TVI_ROOT, L(111,"Colors and Fonts"),   2)
           FF_TreeView_InsertItem (hWndTreeview, TVI_ROOT, L(112,"Compiler Setup"),     3)
           FF_TreeView_InsertItem (hWndTreeview, TVI_ROOT, L(129,"Localization"),       4)
           FF_TreeView_InsertItem (hWndTreeview, TVI_ROOT, L(177,"FreeBASIC Keywords"), 5)

   ' Load all of the child dialogs
   frmOptionsGeneral_Show( pWindow->hWindow )
   frmOptionsEditor_Show( pWindow->hWindow )
   frmOptionsColors_Show( pWindow->hWindow )
   frmOptionsCompiler_Show( pWindow->hWindow )
   frmOptionsLocal_Show( pWindow->hWindow )
   frmOptionsKeywords_Show( pWindow->hWindow )

   ' Select the first item "Code Editor"
   TreeView_SelectItem( hWndTreeview, hItem)

   SetFocus hWndTreeview
   
   ' Process Windows messages
   Function = pWindow->DoEvents(nCmdShow)
   
   ' Delete the frmOptions CWindow class manually allocated memory 
   Delete pWindow

   ' Delete the child windows releasing their manually allocated memory 
   pWindow = AfxCWindowPtr(HWND_FRMOPTIONSGENERAL):   Delete pWindow
   pWindow = AfxCWindowPtr(HWND_FRMOPTIONSEDITOR):    Delete pWindow
   pWindow = AfxCWindowPtr(HWND_FRMOPTIONSCOLORS):    Delete pWindow
   pWindow = AfxCWindowPtr(HWND_FRMOPTIONSCOMPILER):  Delete pWindow
   pWindow = AfxCWindowPtr(HWND_FRMOPTIONSLOCAL):     Delete pWindow
   pWindow = AfxCWindowPtr(HWND_FRMOPTIONSKEYWORDS):  Delete pWindow

End Function

