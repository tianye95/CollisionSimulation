// Fill out your copyright notice in the Description page of Project Settings.

#include "MyWedgeActor.h"

AMyWedgeActor::AMyWedgeActor()
{
    
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    
    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
    RootComponent = MeshComponent;
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshComponentAsset(TEXT("/Game/StarterContent/Shapes/Shape_Wedge_A.Shape_Wedge_A"));
    
    ObjectSize = 15.0f;
    ObjectRelativeLocation = FVector(0.0f, 0.0f, 0.0f);
    ObjectRelativeRotation = FRotator(0.0f, 0.0f, 0.0f);
    ObjectRelativeScale = FVector(ObjectSize/50.0);
    ObjectColor = FLinearColor( 102.0f/255.0f, 46.0f/255.0f, 28.0f/255.0f );
    
    if (MeshComponentAsset.Succeeded())
    {
        MeshComponent->SetStaticMesh(MeshComponentAsset.Object);
        AObjectActor::InitilizeObject();
    }
    
    RelativeForceLocationBottom = FVector(-15.0f, 15.0f, -15.0f);
    RelativeForceLocationCenter = FVector(0.0f, 0.0f, 0.0f);
    RelativeForceLocationTop =  FVector(0.0f, 15.0f, 15.0f);
    
    //Notes:
    //    Cube has size 30*30*30
    //    The local origin is at the (15,15,0) position of the cube
    
}