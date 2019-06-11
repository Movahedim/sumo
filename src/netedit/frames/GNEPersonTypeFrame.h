/****************************************************************************/
// Eclipse SUMO, Simulation of Urban MObility; see https://eclipse.org/sumo
// Copyright (C) 2001-2019 German Aerospace Center (DLR) and others.
// This program and the accompanying materials
// are made available under the terms of the Eclipse Public License v2.0
// which accompanies this distribution, and is available at
// http://www.eclipse.org/legal/epl-v20.html
// SPDX-License-Identifier: EPL-2.0
/****************************************************************************/
/// @file    GNEPersonTypeFrame.h
/// @author  Pablo Alvarez Lopez
/// @date    Jun 2019
/// @version $Id$
///
// The Widget for edit person type (VTypes with vclass='pedestrian) elements
/****************************************************************************/
#ifndef GNEPersonTypeFrame_h
#define GNEPersonTypeFrame_h


// ===========================================================================
// included modules
// ===========================================================================
#include "GNEFrame.h"

// ===========================================================================
// class declarations
// ===========================================================================

class GNEPerson;

// ===========================================================================
// class definitions
// ===========================================================================
/**
 * @class GNEPersonTypeFrame
 */
class GNEPersonTypeFrame : public GNEFrame {

public:

    // ===========================================================================
    // class PersonTypeSelector
    // ===========================================================================

    class PersonTypeSelector : protected FXGroupBox {
        /// @brief FOX-declaration
        FXDECLARE(GNEPersonTypeFrame::PersonTypeSelector)

    public:
        /// @brief constructor
        PersonTypeSelector(GNEPersonTypeFrame* vehicleTypeFrameParent);

        /// @brief destructor
        ~PersonTypeSelector();

        /// @brief get current Vehicle Type
        GNEDemandElement* getCurrentPersonType() const;

        /// @brief set current Vehicle Type
        void setCurrentPersonType(GNEDemandElement* vType);

        /// @brief refresh vehicle type
        void refreshPersonTypeSelector();

        /// @name FOX-callbacks
        /// @{
        /// @brief Called when the user select another element in ComboBox
        long onCmdSelectItem(FXObject*, FXSelector, void*);
        /// @}

    protected:
        /// @brief FOX needs this
        PersonTypeSelector() {}

    private:
        /// @brief pointer to Frame Parent
        GNEPersonTypeFrame* myPersonTypeFrameParent;

        /// @brief pointer to current vehicle type
        GNEDemandElement* myCurrentPersonType;

        /// @brief comboBox with the list of elements type
        FXComboBox* myTypeMatchBox;
    };

    // ===========================================================================
    // class PersonTypeEditor
    // ===========================================================================

    class PersonTypeEditor : protected FXGroupBox {
        /// @brief FOX-declaration
        FXDECLARE(GNEPersonTypeFrame::PersonTypeEditor)

    public:
        /// @brief constructor
        PersonTypeEditor(GNEPersonTypeFrame* vehicleTypeFrameParent);

        /// @brief destructor
        ~PersonTypeEditor();

        /// @brief show PersonTypeEditor modul
        void showPersonTypeEditorModul();

        /// @brief hide PersonTypeEditor box
        void hidePersonTypeEditorModul();

        /// @brief update PersonTypeEditor modul
        void refreshPersonTypeEditorModul();

        /// @name FOX-callbacks
        /// @{
        /// @brief Called when "Vreate Vehicle Type" button is clicked
        long onCmdCreatePersonType(FXObject*, FXSelector, void*);

        /// @brief Called when "Delete Vehicle Type" button is clicked
        long onCmdDeletePersonType(FXObject*, FXSelector, void*);

        /// @brief Called when "Delete Vehicle Type" button is clicked
        long onCmdResetPersonType(FXObject*, FXSelector, void*);

        /// @brief Called when "Copy Vehicle Type" button is clicked
        long onCmdCopyPersonType(FXObject*, FXSelector, void*);
        /// @}

    protected:
        /// @brief FOX needs this
        PersonTypeEditor() {};

    private:
        /// @brief pointer to vehicle type Frame Parent
        GNEPersonTypeFrame* myPersonTypeFrameParent;

        /// @brief "create vehicle type" button
        FXButton* myCreatePersonTypeButton;

        /// @brief "delete vehicle type" button
        FXButton* myDeletePersonTypeButton;

        /// @brief "delete default vehicle type" button
        FXButton* myResetDefaultPersonTypeButton;

        /// @brief "copy vehicle type"
        FXButton* myCopyPersonTypeButton;
    };

    /**@brief Constructor
     * @brief parent FXHorizontalFrame in which this GNEFrame is placed
     * @brief viewNet viewNet that uses this GNEFrame
     */
    GNEPersonTypeFrame(FXHorizontalFrame* horizontalFrameParent, GNEViewNet* viewNet);

    /// @brief Destructor
    ~GNEPersonTypeFrame();

    /// @brief show Frame
    void show();

    /// @brief get vehicle type selector
    PersonTypeSelector* getPersonTypeSelector() const;

protected:
    /// @brief function called after set a valid attribute in AttributeCreator/AttributeEditor/GenericParametersEditor/...
    void updateFrameAfterChangeAttribute();

    /// @brief open AttributesCreator extended dialog (used for editing advance attributes of Vehicle Types)
    void openAttributesEditorExtendedDialog();

private:
    /// @brief vehicle type selector
    PersonTypeSelector* myPersonTypeSelector;

    /// @brief editorinternal vehicle type attributes
    AttributesEditor* myPersonTypeAttributesEditor;

    /// @brief modul for open extended attributes dialog
    AttributesEditorExtended* myAttributesEditorExtended;

    /// @brief Vehicle Type editor (Create, copy, etc.)
    PersonTypeEditor* myPersonTypeEditor;
};


#endif

/****************************************************************************/