#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# contract/core/classes.py - classes module with cross-industry contract building blocks
#
# This file is part of OndALear  collection of open source components
#
# This software is provided 'as-is', without any express or implied
# warranty.  In no event will the authors be held liable for any damages
# arising from the use of this software.
#
# Copyright (C) 2008 Amnon Janiv <amnon.janiv@ondalear.com>
#

# Initial version: 2008-02-01
# Author: Amnon Janiv <amnon.janiv@ondalear.com>


"""
.. module:: contract.core.classes
   :synopsis: Fundamental classes required for contract composition module

Classes required to composes complex industry agnostic contracts.

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>

"""

__revision__ = '$Id: $'

__version__ = '0.0.1'




from emf.core.emfutil import check_list
from busobject.core.classes import BusinessObject
from busobject.core.classes import BusinessObjectList
from busobject.core.classes import BusinessWorkspace



class BusinessContractClauseGrouping(BusinessObjectList):
    
    """
    Groups other clauses to facilitate their management. 
    This is a useful construct in contracts where there are  a large number of clauses, and 
    where sets of clauses can be grouped into clusters 
    """
    def __init__(self):
        super(BusinessContractClauseGrouping, self).__init__()
        
       
     
    
# End Class BusinessContractClauseGrouping Definition


class BusinessContractClauseList(BusinessObjectList):
    
    """
    Contract clause container
    """
    def __init__(self):
        super(BusinessContractClauseList, self).__init__()
    
    
   
# end class BusinessContractClauseList Definition


class BusinessContractList(BusinessObjectList):
    """
    An abstraction for a list of contracts
    """
    
    def __init__(self, contracts_attr=None, contracts=None):
        super(BusinessContractList, self).__init__()
     
    def get_contracts(self): 
        return super(BusinessContractList, self).get_list()
    def set_contracts(self, contracts): 
        super(BusinessContractList, self).set_list(contracts)
    contracts=property(get_contracts, set_contracts)
    def add_contracts(self, contract): 
        """Add a contract to the list
        
        :param contract: A business contract
        :type contract: BusinessContract.
        """
        super(BusinessContractList, self).add_list(value)
         
     
    
# end Class BusinessContractList Definition


class BusinessContractWorkspace(BusinessWorkspace):
    """
    Container for contracts for which there is 'work in progress'.
    Allows contract designer to create a master agreement contract,
    assemble multiple contract trees, and establish links between them.
    
    """
     
    def __init__(self):
        super(BusinessContractWorkspace, self).__init__()
         
        self._contracts = None
        self._contractLists = None
         
    
    def get_contracts(self): 
        return self._contracts
    def set_contracts(self, contracts): 
        self._contracts = contracts
    contracts=property(get_contracts, set_contracts)
    @check_list
    def add_contracts(self, value):
        """Add a contract to the workspace
        
        :param contract: A business contract
        :type contract: BusinessContract.
        """
        self._contracts.append(value)
     
    def get_contractLists(self): 
        return self._contractLists
    def set_contractLists(self, contractLists): 
        self._contractLists = contractLists
    contractLists=property(get_contractLists, set_contractLists)
    @check_list
    def add_contractLists(self, value): 
        self._contractLists.append(value)
    
   
# End Class BusinessContractWorkspace Definition


class ContractPart(BusinessObject):
    """
    Base class for classes used in contract composition.
    
    If it is not derived from ContractPart, it cannot be aggregated
    into a contract.
    """
    def __init__(self):
        super(ContractPart, self).__init__()
         
     
# End Class ContractPart Definition


class ContractPartSpec(BusinessObject):
    
    """
    Base class defining the details specs for the contract part.
    
    Provides facilities for associating attachments with the contract.
    """
    def __init__(self):
        super(ContractPartSpec, self).__init__()
        self._contractableSpec = None
        self._attachements = None
        
   
    def get_contractableSpec(self): 
        return self._contractableSpec
    def set_contractableSpec(self, contractableSpec): 
        self._contractableSpec = contractableSpec
    contractableSpec=property(get_contractableSpec, set_contractableSpec)
     
    def get_attachements(self): 
        return self._attachements
    def set_attachements(self, attachements): 
        self._attachements = attachements
    attachements=property(get_attachements, set_attachements)
    @check_list
    def add_attachements(self, value): 
        self._attachements.append(value)
   
   
# End Class ContractPartSpec Definition


class ContractSpec(ContractPartSpec):
    """
    Describes the contract details summary.
    
    These include including a brief description, and the parties to the contract
    
    """
     
    def __init__(self):
         
        super(ContractSpec, self).__init__()
        self._shortcut = None
        self._parties = None #TODO: rename to parties in Java, xsd
         
    def get_shortcut(self): 
        return self._shortcut
    def set_shortcut(self, shortcut): 
        self._shortcut = shortcut
    shortcut=property(get_shortcut, set_shortcut)
        
    def get_parties(self): 
        return self._parties
    def set_parties(self, list): 
        self._parties = list
    parties=property(get_parties, set_parties)
    @check_list
    def add_parties(self, value): 
        self._parties.append(value)
     
    
    
# End Class ContractSpec Definition


class ContractInstructionSpec(ContractPartSpec):
    """
    Describes specific instructions.
    
    These include source/target - receiver/payer
    
    """
    #
    # TODO: rename/review attributes
    def __init__(self):
        super(ContractInstructionSpec, self).__init__()
        self._source = None
        self._target = None
   
    def get_source(self): 
        return self._source
    def set_source(self, source): 
        self._source = source
    source=property(get_source, set_source)
    
    def get_target(self): 
        return self._target
    def set_target(self, target): 
        self._target = target
    target=property(get_target, set_target)
  
    
    
# End Class ContractInstructionSpec Definition


class ContractClauseSpec(ContractPartSpec):
    """
    Describes the details for a clause.

    """
    
    def __init__(self):
        super(ContractClauseSpec, self).__init__()
        
    
# End Class ContractClauseSpec Definition


class ContractActionSpec(ContractPartSpec):
    """
    Describes the details for the action.

    """
    def __init__(self):
        super(ContractActionSpec, self).__init__()
   
# End Class ContractActionSpec Definition



class BusinessContractInstruction(ContractPart):
    """
    Contained within the action portion of the contract clause, instructions provide a level of detail on what needs to be performed during the processing of a contract action.  
    Some sample actions include:
    
    - Pay
    - Receive

    More than one set of instructions may be specified with a contract clause action.

    Instruction types include:
    
    - Give
    - Receive
    - User Defined
    """
    def __init__(self):
        super(BusinessContractInstruction, self).__init__()
        self._instructionType = None
        self._instructionSpec = None
        
     
    def get_instructionType(self): 
        return self._instructionType
    def set_instructionType(self, instructionType): 
        self._instructionType = instructionType
    instructionType = property(get_instructionType, set_instructionType)
    
    def get_instructionSpec(self): 
        return self._instructionSpec
    def set_instructionSpec(self, instructionSpec): 
        self._instructionSpec = instructionSpec
    instructionSpec=property(get_instructionSpec, set_instructionSpec)
   
    
# End Class BusinessContractInstruction Definition



class BusinessContractClause(ContractPart):
    """
    Captures the liabilities of the parties to the contract
    Rules which define the resources a party to a contract needs to deliver, when the delivery needs to take place, and how.  
    It specifies the obligations that a party to a contract commits to.  
    Contract may contain zero or more contract clauses.
    
    General expression is:
        Between time t1 and t2 On  “Clause X“ Action(action spec)

    Clauses may be organized into groups to facilitate their management.  
    
    Following are the primary clause types:
    
    - Time Clause.  An obligation that is time bounded.
        What we would like to express when using a Time clause is an expression of the following syntax:
        On   the specified time, execute one of the following actions:

        For example:
        
        * On Time “Dec 15, 2007”  Action “Transfer To Cash”
        * On Time “Dec 15, 2007”  Action “Create  Clause to transfer cash”

        The second example above demonstrates forward scheduling.
    - Decision Clause. An obligation that is decision/optionality bounded.
        For example:
        + On Decision “Exercise”  Action “Acquire Underlying Contract”

    - Contingent Clause. An obligation that is bound to some contingency.
       From T1 to T2 ContingentClause(“DEFAULT Reference Obligation”), Action(“Transfer PAY|RECEIVE Recovery Payout) &  
       Action(“End Contract”)

    - User Defined.

    """
    
    def __init__(self):
        super(BusinessContractClause, self).__init__()
        self._clauseType = None
        self._clauseSpec = None
        self._actions = None
        
     
    def get_clauseType(self): 
        return self._clauseType
    def set_clauseType(self, clauseType): 
        self._clauseType = clauseType
    clauseType=property(get_clauseType, set_clauseType)
    
    def get_clauseSpec(self): 
        return self._clauseSpec
    def set_clauseSpec(self, clauseSpec): 
        self._clauseSpec = clauseSpec
    clauseSpec=property(get_clauseSpec, set_clauseSpec)
     
    def get_actions(self): 
        return self._actions
    def set_actions(self, actions): 
        self._actions = actions
    actions=property(get_actions, set_actions)
    
    @check_list
    def add_actions(self, value): 
        """Add an action to the clause"""
        self._actions.append(value)
     
    
# End Class BusinessContractClause Definition




class BusinessContractAction(ContractPart):
    """
    Part of a contract clause which specifies what is to be done when
    interpreting the clause.  It describes what needs to be done within a clause.  
    More than one such instances may be contained within a clause.
    
    Some sample actions include:
    
    - Create new contract from existing contract
    - End contract
    - Replace clauses
    - Schedule clause
    - Send/Transfer
    
    Primary types of action include:
    
    - Exec. Execution an action such as contract termination
    - Transfer. Transfer a resource between patries.
    - Select.  Selection from several options (i.e. which contract to execute)
    - User Defined.
    """
    def __init__(self):
        super(BusinessContractAction, self).__init__()
        self._actionType = None
        self._actionSpec = None
        self._instructions = None
         
     
    def get_actionType(self): 
        return self._actionType
    def set_actionType(self, actionType): 
        self._actionType = actionType
    actionType=property(get_actionType, set_actionType)
    
    def get_actionSpec(self): 
        return self._actionSpec
    def set_actionSpec(self, actionSpec): 
        self._actionSpec = actionSpec
    actionSpec=property(get_actionSpec, set_actionSpec)
    
    def get_instructions(self): 
        return self._instructions
    def set_instructions(self, instructions): 
        self._instructions = instructions
    instructions=property(get_instructions, set_instructions)
    
    @check_list
    def add_instructions(self, value): 
        self._instructions.append(value)
    
    
# End Class BusinessContractAction Definition


class BusinessContract(ContractPart):
    """
    A financial contract is an agreement between parties or agents for the exchange of financial resources. Within the financial industry our focus is on explicit contracts which are backed by formal documentation. A contract is made of contract clauses, which define the obligations which the parties assume and the resources that are to be exchanged.  These rules span payout instructions, but cover other aspects including delivery instructions, documentation, and other aspects. A contract is typically instantiated from a contract template and contract parameters.  Contract templates are incomplete contracts that have been prepared for easy duplication and thus increase the efficiency of contract instantiation.  It is not absolutely essential for a contract to be instantiated from a template; contract clauses can be defined on the fly.  Contract parameters can be simple constants or data whose value needs to be resolved at a later date (i.e. rates that are determined at a future date). A contract can be made of other contracts.  Embedded within the contract definition are financial products definitions, both listed and OTC.  The product portion of a contract describes the resource, which can be referenced by more than one contract, which is being operated on.

    A financial contract is a structure that can serve the needs of its multiple constituents, including clients, front office, mid-office, and back office.  Each of these constituents is exposed to the relevant aspects of the contract using customized ‘lens’ or views.  
    A contract representation may not be perfectly suitable for the processes which are required to analyze it.  For example, one of the challenges is to identify a contract representation that facilitates its processing   by valuation processes, and whose emphasis is on memory efficiency and processing performance.  Contract needs to be translated into a form that is independent of the underlying processing method, into an intermediate form that facilitates its analysis (i.e. valuation).  In essence, the contract definition may be used by processes with different needs, all of which rely on the same basic/complete contract representation, where each process derives only its relevant parts.

    Throughout its life cycle, a contract changes its state in response to events.  The occurrence of an event would result in the contract being transformed, with each transformation resulting in a new version of the contract being created, and with each version of the contract the clauses being revised to reflect the outstanding obligations.  At any given state, the set of events that the contract is sensitive to depends on the contract clauses, including the type of products being exchanged and other rules governing the relationship between the parties. In its final state, the contract is void of outstanding commitments.

    A contract may consist of sub contracts.  Valuation of a contract which has sub contracts is a process of summation of the results of valuing each of the sub contracts.

    Contracts may have links to other contracts.  The type   relationship between the contracts depends on the cause for the establishment of the links.  Some relationships define tight binding between contracts, where a change to one contract could result in changes to the contracts that are linked to it.  Other relationships are structured more loosely.

    There are several dates which govern the life of a contract:
    
    - Acquisition date.  Date the contract was transacted.  The governance of the relations between the parties commences on this date.  Prior to this date, the contract was in a ‘preparation’ state, without any legal obligations.
    - Effective date. Date contract clauses become effective and the parties need to perform as per the obligations stipulated within the contract clauses.
    - Maturity date. Date contract expires.

    The time horizon for contract begins with its effective date and ends with its maturity date.


    Contract life cycle management is the art of monitoring events including time, exercise, fixing, amendments, assignments, cancellation, and more.  One needs to understand how over time the contract evolves, and what the side effects of these external stimuli are on the generation of payments and receipt instructions.  Contracts are sensitive to external stimuli, and one of the key challenges is to provide a holistic view of the events a portfolio of contracts is exposed to. The degree of automation of contract life cycle management has direct correlation to the quality of life of professionals required to manage it.  The automatic monitoring of the external stimuli impact on contract and the contract transformation from pre-event clauses to post event clauses all with a complete trace is at the heart of event management.  Embedded within this automation is the ability to analyze the impact of entry into the contract and its ramification to a wide set of business processed including pricing, accounting, decision support, and other business workflows.

    There is a legal obligation to maintain an audit trail of all the changes that are made to a contract in response to an event.  One should be able to recreate the state of a contract at any given time from this audit trail.  A contract event trace is comprised of a finite set of events which is time ordered.

    As a contract goes through its life cycle, it transitions through several states:
    
    - Pre
    - Ready
    - Active
    - Suspended
    - Post
    - End


    Some of the key aspects of a financial contract to bear in mind as we seek to define a modeling language include:
    
    - Commitment – obligation to transfer resources between parties 
    - It may prescribe a sequential execution of sub contracts, concurrent execution of sub contracts, the execution of one of a number of sub contracts, and repeated execution of sub contracts
    - Each of the elements of contracts have time constraints

    """
    def __init__(self):
        super(BusinessContract, self).__init__()
        self._contractType = None
        self._contractDomain = None
        self._businessLine = None
        self._contractSpec = None 
        self._contracts = None
        self._clauses = None
        self._clauseGroups = None
        self._busObjectLists = None 
        
    #
    # Structure
    #
    def get_contractType(self): 
        return self._contractType
    def set_contractType(self, contractType): 
        self._contractType = contractType
    contractType=property(get_contractType, set_contractType, None, "Contract type")
    
    def get_contractDomain(self): 
        return self._contractDomain
    def set_contractDomain(self, contractDomain): 
        self._contractDomain = contractDomain
    contractDomain=property(get_contractDomain, set_contractDomain, None, "Contract domain")
   
    def get_businessLine(self): 
        return self._businessLine
    def set_businessLine(self, businessLine): 
        self._businessLine = businessLine
    businessLine=property(get_businessLine, set_businessLine, None, "Business line")
    
    def get_contractSpec(self): 
        return self._contractSpec
    def set_contractSpec(self, contractSpec): 
        self._contractSpec = contractSpec
    contractSpec=property(get_contractSpec, set_contractSpec, None, "Contract details")
    
    def get_contracts(self): 
        return self._contracts
    def set_contracts(self, contracts): 
        self._contracts = contracts
    contracts=property(get_contracts, set_contracts, None, "Contract list")
    @check_list
    def add_contracts(self, contract): 
        """Add a contract to object graph
        
        :param contract: A business contract
        :type contract: BusinessContract.
        
        """
        self._contracts.append(contract)
    
    def get_clauses(self): 
        return self._clauses
    def set_clauses(self, clauses): 
        self._clauses = clauses
    clauses=property(get_clauses, set_clauses,None,"Independent clause list")
    @check_list
    def add_clauses(self, value): 
        self._clauses.append(value)
    
    def get_clauseGroups(self): 
        return self._clauseGroups
    def set_clauseGroups(self, clauseGroups): 
        self._clauseGroups = clauseGroups
    clauseGroups=property(get_clauseGroups, set_clauseGroups,None,"List of clause groups")
    @check_list
    def add_clauseGroups(self, value): 
        self._clauseGroups.append(value)
    
    def get_busObjectLists(self): 
        return self._busObjectLists
    def set_busObjectLists(self, lists): 
        self._busObjectLists = lists
    busObjectLists=property(get_busObjectLists, set_busObjectLists,None,"Referenced business objects")
    
    @check_list
    def add_busObjectLists(self, value): 
        self._busObjectLists.append(value)
    #
    #Run time
    #
    def __add__(self, contract):
        """
        Adds two contracts returning a contract containing the two underlying contracts.
        This is one of the operations required to support contract composition.
        
        The code snippet below would result in contract "c3" being comprised 
        of contracts "c1" and contracts "c2".
        c3 = c1 + c2
        """
        pkg = self.eClass.ePackage
        factory = pkg.factory
        new_ctrct = factory.create_BusinessContract()
        new_ctrct.add_contracts(self)
        new_ctrct.add_contracts(contract)
        return new_ctrct
         
    def __iadd__(self, contract):
        """
        Add a contact to 'self', modifying the original contract.
        
        The code snippet below would result in contract "c1" being updated
        to contain contract c2.
        c1 += c2
        """
        self.add_contracts(contract)
        return self
    
# End Class BusinessContract Definition